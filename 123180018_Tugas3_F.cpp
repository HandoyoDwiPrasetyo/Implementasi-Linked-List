#include <iostream>
#define max 12
#define true 1
#define false 0
using namespace std;
typedef int typeinfo;
typedef struct { int info; int next;} typenode;
typenode elemen [max];
int list ,akhirlist,kosong,akhirkosong;
int listkosong();
void buatlist ();
void sisipnode (typeinfo IB);
void hapusnode (typeinfo IH);
typeinfo IB, IH;
void cetaklist();

int main()
{
	int pilih;
	char kembali;
	
	buatlist();
	do{
		cout<<"-------------------------------------"<<endl;
		cout<<"      ==> Linked List Array <=="<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Menu : "<<endl;
		cout<<" 1. Masukkan Node"<<endl;
		cout<<" 2. Cetak Node"<<endl;
		cout<<" 3. Hapus Node"<<endl;
		cout<<"Pilih Menu : ";cin>>pilih;
		cout<<"------------------------------------"<<endl;		
		switch (pilih){
			case 1 :
				cout<<"------------------------------------"<<endl;
				cout<<"====== Menu Input Node"<<endl;	
				cetaklist();
				cout<<"Masukkan node "<<" : ";cin>>IB;
				sisipnode(IB);
				cetaklist();

			break;
			case 2 :
				cout<<"------------------------------------"<<endl;
				cout<<"====== Menu Cetak Node"<<endl;
				cout<<"List  = ";
				cetaklist();
			break;
			case 3:
				cout<<"------------------------------------"<<endl;
				cout<<"====== Menu Hapus Node"<<endl;
				cout<<"Masukkan Node yang ingin di Hapus : ";cin>>IH;
				hapusnode(IH);
				cout<<"/nlist baru =";
				cetaklist();
			break;
		}cout<<"Kembali ke menu (y/n) ?";cin>>kembali;
	} while (kembali=='y'||kembali=='Y');

}
void buatlist(){
	list=5;
	kosong=3;
	akhirlist=10;
	akhirkosong=4;
	elemen[1].info=25;	elemen[1].next=8;
	elemen[2].info=0;	elemen[2].next=9;
	elemen[3].info=0;	elemen[3].next=6;
	elemen[4].info=0;	elemen[4].next=0;
	elemen[5].info=10;	elemen[5].next=7;
	elemen[6].info=0;	elemen[6].next=2;
	elemen[7].info=15;	elemen[7].next=1;
	elemen[8].info=40;	elemen[8].next=10;
	elemen[9].info=0;	elemen[9].next=4;
	elemen[10].info=60;	elemen[10].next=0;
}

int listkosong(){
	if (list==0)
	return (true);
	else
	return (false);
}
void sisipnode(typeinfo IB){
	int listbaru,k,m,n,x;
	//sisip Awal
	if (IB<elemen[list].info){
		listbaru=kosong;//3
		kosong=elemen[kosong].next;
		elemen [listbaru].info=IB;
		elemen [listbaru].next=list;
		list=listbaru;
	}
	else
	//sisip diakhir
	if (IB>elemen[akhirlist].info){
		listbaru=kosong;
		kosong=elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=0;
		elemen[akhirlist].next=listbaru;
		akhirlist=listbaru;
	}
	else
	//sisip ditengah
	{ n=list;
		x=elemen[kosong].next;
		while (IB>x)
		{m=n;
			n=elemen[n].next;
			x=elemen[n].info;
		}
		k=elemen[kosong].next;
		elemen[m].next=kosong;
		elemen[kosong].info=IB;
		elemen [kosong].next=n;
		kosong=k;
	}
}
void cetaklist(){
	int n,m;
	n=list;//5
	m=kosong;//3
	cout<<endl<<"= isi list :\n";
	do{ 
		cout <<elemen[n].info<<" ";
		n=elemen [n].next;
	}while (elemen[n].next!=0);
	cout<<" "<<elemen[akhirlist].info<<endl;
	cout<<endl<<"= index tempat-tempat kosong : "<<endl;
	do{
		cout<< m << " ";
		m=elemen[m].next;
	}while (elemen[m].next!=0);
	cout<< " " << akhirkosong;
	cout<<endl;
}

void hapusnode(int IH){
	int listbaru,k,m,n,x;
	//hapus di awal
	if (IH==elemen[list].info)
	{listbaru=elemen[list].next;
		k=kosong;
		kosong=list;
		list=listbaru;
		elemen[kosong].next=k;
	}
else 
{
	n=list;
	x=elemen[kosong].next;
		while (IH>x){
			m=n;
			n=elemen[n].next;
			x=elemen[n].info;
		}
		if (n==akhirlist){
			akhirlist=m;
			elemen[akhirlist].next=0;
			elemen[akhirkosong].next=n;
			akhirkosong=n;
			elemen[akhirkosong].info=0;
		}
		else{
			elemen[m].next=elemen[n].next;
			elemen[akhirkosong].next=n;
			akhirkosong=n;
			elemen[akhirkosong].info=0;
			elemen[akhirkosong].next=0;
		}
		
}
}
	
	

