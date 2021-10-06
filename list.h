#include<iostream>
#include<string>
#include<fstream>
using namespace std;


//khai bao cau truc sinh vien
struct word{
    string eng;
    string meaning;
    float diemtb;
};

typedef struct word WORD;

//Khai bao cau truc 1 node sinh viet
struct node{
    WORD data; 
    struct node *pNext;
};
typedef struct node NODE;

struct list{
    NODE *pHead; 
    NODE *pTail; 
};
typedef struct list LIST;

void Create(LIST &l){
    l.pHead = NULL; 
    l.pTail = NULL;
}

NODE *CreateANode(WORD x){
    NODE *p = new NODE; 
    p->data = x; //Dua du lieu cua sinh vien x vao data cua node p
    p->pNext = NULL;
    return p;
}

void releaseList(LIST &l){
    NODE *k = NULL;
    while(l.pHead != NULL){
        k = l.pHead;
        l.pHead = l.pHead -> pNext;
        delete k;
    }
}

void addNodeToFirst(LIST &l, NODE *p){
    if(l.pHead == NULL){ 
        l.pHead = l.pTail = p;
    }
    else {
        p->pNext = l.pHead; //Tao moi lien ket giua 2 node 
        l.pHead = p;
    }

}

void addNodeToLast(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p; 
        l.pTail = p;
    }

}

//Ham Doc du lieu 1 sinh vien tu file WORD.txt
void readData1SV(ifstream &filein, WORD &sv){
    //đọc họ tên sinh viên
    getline(filein, sv.eng, ','); //Đọc đến dấu phẩy thì dừng
    filein.seekg(1, ios_base::cur);
    getline(filein, sv.meaning, ',');
    filein.seekg(1, ios_base::cur);
    filein >> sv.diemtb;
    //Tạo biến tạm để đọc kí tự xuống dòng ở cuối dòng
    string temp;
    getline(filein, temp);
}

//Đọc danh sách tất cả sinh viên từ file
void readDataAllSV(ifstream &filein, LIST &l){
    //đọc đến cuối file thì dừng, filein.eof() là hàm cuối file, nếu không phải cuối file thì cứ đọc
    while (!filein.eof()){
        //Bước 1: đọc thông tin 1 sinh viên
        WORD sv;
        readData1SV(filein ,sv);
        //Bước 2: Khởi tạo 1 node WORD
        NODE *p = CreateANode(sv);
        //Bước 3: thêm node p = sinh viên vào danh sách liên kết đơn các SV
        addNodeToLast(l, p);

    }
}

//Hàm xuất để test dữ liệu
void output1SV(WORD sv){
    cout << "Ho ten   : " << sv.eng << endl;
    cout << "meaning     : " << sv.meaning  << endl;
    cout << "Diem TB  : " << sv.diemtb << endl;
}

void outputListSV(LIST l){
    int dem = 1;
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        cout << "\n\t SINH VIEN THU " << dem++ << endl;
        output1SV(k->data); //Chi xuat ra thong tin sv
    }
}
/*ALL FUNCTIONS NEEEDED FOR SORT AND SAVE FILE*/
//Hàm ghi thông tin một sv vào file 
void writeData1SV(ofstream &fileout, WORD sv){
    fileout << sv.eng << ", ";
    fileout << sv.meaning << ", ";
    fileout << sv.diemtb;
}

void swapData2Nodes(WORD &x, WORD &y){//2 bien data co kieu du lieu WORD
    WORD temp = x; 
    x = y;
    y = temp;
}

void sortIncreasedPoint(LIST &l){
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){ //giong nhu cho i chay tu dau mang -> cuoi mang
        for(NODE * h = k->pNext; h != NULL; h = h->pNext){//Cho j chay tu i den cuoi mang
            if(k->data.diemtb > h->data.diemtb){
                swapData2Nodes(k->data, h->data); //Hoan vi data, chu khong the hoan vi 2 cai nodes. 
            }
        }
    }
}
//Sap xep danh sach sv theo diem -> luu vao file SapxepDiem.txt
//Chỉ truyền vào LIST l, không cần lưu lại trong danh sách đó mà lưu lại ở file khác, nên lúc truyền vào không cần LIST &l, vì không cần thay đổi dữ liệu trong LIST
void saveFileSortPoints(LIST l){
    ofstream fileout;
    fileout.open("SapxepDiem.txt", ios::out);
    sortIncreasedPoint(l);
    //Dùng vòng lặp lưu tất cả thông tin sv vào file.
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        writeData1SV(fileout, k->data);
        fileout << endl;
    }
    fileout.close();
}



void deleteNodeFirst(LIST &l){
    if(l.pHead == NULL) return;
    NODE *p = l.pHead; //node p la node se xoa
    l.pHead = l.pHead->pNext; //cap nhat pHead la node tiep theo tro toi
    delete p;
}

void deleteNodeLast(LIST &l){
    if(l.pHead == NULL) return;
    if(l.pHead->pNext == NULL) deleteNodeFirst(l);
    // duyet tu dau danh sach toi vi tri ke cuoi
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->pNext == l.pTail){
            delete l.pTail;
            k->pNext = NULL; //Cho con tro node ke cuoi tro den NULL
            l.pTail = k;//Cap nhat lai pTail
            return;
        }
    }

}
