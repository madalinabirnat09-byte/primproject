#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Carte {
    string cod;
    string titlu;
    string autor;
    int an;
    string limba;
    float pret;
};

struct Inchiriere {
    string cod_carte;
    string nume;
    string prenume;
    int ziua;
    int luna;
    int anul;
    int ziua_termen;
    int luna_termen;
    int anul_termen;
};
void afisareCarti() {
    ifstream f("Book.txt");
    cout << "\n ჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻ARHIVA CĂRȚILOR ჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻\n";
    Carte c[100];
    int o=1;
    while (f>>c[o].cod>>c[o].titlu>>c[o].autor>>c[o].an>>c[o].limba>>c[o].pret){
        o++;
    }
    for(int i=1; i<o; i++)
    cout<<setw(5)<<c[i].cod<<setw(31)<<c[i].titlu<<setw(20)<<c[i].autor<<setw(10)<<c[i].an<<setw(10)<<c[i].limba<<setw(5)<<c[i].pret<<endl;
    }
void afisareInchirieri() {
    ifstream f("Rent.txt");
    cout << "\n ჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻ LISTA ABONAȚILOR ჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻჻\n";
    Inchiriere c[100];
    int o=1;
    while (f>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    for(int i=1; i<o; i++)
    cout<<setw(5)<<c[i].cod_carte<<setw(11)<<c[i].nume<<setw(11)<<c[i].prenume<<setw(6)<<c[i].ziua<<setw(6)<<c[i].luna<<setw(6)<<c[i].anul<<setw(6)<<c[i].ziua_termen<<setw(4)<<c[i].luna_termen<<setw(6)<<c[i].anul_termen<<endl;
    }
    
void adaugareCarte() {
    int o=1;
    bool verify=true;
    ifstream fin("Book.txt");
    Carte a,c[100]; // se declară o variabilă de tip Carte
    while (fin>>c[o].cod>>c[o].titlu>>c[o].autor>>c[o].an>>c[o].limba>>c[o].pret){
        o++;}
    ofstream fout("Book.txt", ios::app); //noile date vor fi scrise la finalul fișierului existent,
                                         //fără a șterge ce era înainte
    cin>>a.cod>>a.titlu>>a.autor>>a.an>>a.limba>>a.pret; //citește de la tastatură atributele cărții
    for(int i=1; i<o; i++){
        if(a.cod==c[i].cod){
        verify=false;//verifică daca deja exista asa carte
    }} //Scrie în fișier datele citite, separate prin spațiu, pe o linie nouă
    if(verify) fout<<endl<<a.cod<<" "<<a.titlu<<" "<<a.autor<<" "<<a.an<<" "<<a.limba<<" "<<a.pret<<endl;
    else if(!verify) cout<<"Asa carte deja exista\n"; }
    
    
void adaugareInchiriere() {
    Inchiriere a,c[100];
    bool verify=true;
    ifstream fin("Rent.txt");
    int o=1,count=0;
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++; //citește linie cu linie informațiile
    }
    ofstream fout("Rent.txt", ios::app);//noile date sunt adăugate la sfârșit, fără a le șterge pe cele vechi
    cin>>a.cod_carte>>a.nume>>a.prenume>>a.ziua>>a.luna>>a.anul>>a.ziua_termen>>a.luna_termen>>a.anul_termen;
    for(int i=1; i<o; i++){ //parcurge lista de închirieri deja existente
        if(a.nume == c[i].nume && a.prenume == c[i].prenume){//verifica limita dee carti
            count++;
        }
        if(a.nume == c[i].nume && a.prenume == c[i].prenume && a.cod_carte == c[i].cod_carte){
            verify=false; //verifica duplicat de carte
        }
    }
    if(count<3 && verify==true){//Dacă sunt mai puțin de 3 cărți și nu s-a luat deja acea carte, datele sunt salvate în fișier.
    fout<<endl<<a.cod_carte<<" "<<a.nume<<" "<<a.prenume<<" "<<a.ziua<<" "<<a.luna<<" "<<a.anul<<" "<<a.ziua_termen<<" "<<a.luna_termen<<" "<<a.anul_termen<<endl;
    }
    else if(count==3 || count>3) cout<<"Acest abonat a luat deja 3 carti!\n";
    else if(!verify) cout<<"Acest abonat deja a luat cartea aceasta!\n";
}
void stergereCarte() {
    int o=1;
    string cd;
    cin>>cd;
    ifstream fin("Book.txt");
    Carte c[100];
    while (fin>>c[o].cod>>c[o].titlu>>c[o].autor>>c[o].an>>c[o].limba>>c[o].pret){
        o++;
    }
    ofstream fout("Book.txt", ios::out);
    for(int i=1; i<o; i++){
        if(c[i].cod==cd){
            continue; 
        } 
        else fout<<c[i].cod<<" "<<c[i].titlu<<" "<<c[i].autor<<" "<<c[i].an<<" "<<c[i].limba<<" "<<c[i].pret<<endl;
    } 
}
void stergereInchiriere() {
    int nr, o=1;
    cin>>nr;
    ifstream fin("Rent.txt");
    Inchiriere c[100];
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen
              >>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    ofstream fout("Rent.txt", ios::out);
    for(int i=1; i<o; i++){
        if(i==nr){
            continue;}
            else cout<<"Nu a fost găsit în listă.\n"; break;
        
         fout<<c[i].cod_carte<<" "<<c[i].nume<<" "<<c[i].prenume<<" "<<c[i].ziua<<" "<<c[i].luna<<" "
             <<c[i].anul<<" "<<c[i].ziua_termen<<" "<<c[i].luna_termen<<" "<<c[i].anul_termen<<endl;
    }
}
void modificareCarte() {
    int o=1;
    string cd;
    cin>>cd;
    ifstream fin("Book.txt");
    Carte c[100];
    while (fin>>c[o].cod>>c[o].titlu>>c[o].autor>>c[o].an>>c[o].limba>>c[o].pret){
        o++;
    }
    bool Verify=true;
    ofstream fout("Book.txt", ios::out);
    for(int i=1; i<o; i++){
        if(c[i].cod==cd){
        Verify=false;
           int optiune;
            do {
            cout<<"✴Selectați ce doriți să modificați\n";
            cout<<"1. Codul\n"<<"2. Titlul\n"<<"3. Autorul\n"<<"4. Anul\n"<<"5. Limba\n"<<"6. Prețul\n"<<"7. Ieșire\n";
            cin>>optiune;
            switch(optiune){
                
                case 1: cin>>c[i].cod;
                break;
                case 2: cin>>c[i].titlu;
                break;
                case 3: cin>>c[i].autor;
                break;
                case 4: cin>>c[i].an;
                break;
                case 5: cin>>c[i].limba;
                break;
                case 6: cin>>c[i].pret;
                break;
                case 7: continue;
                break;
                default: cout<<"Nu există așa opțiune. Reîncercați.\n";
                break;
            }
            
            } while (optiune!=7);
            fout<<c[i].cod<<" "<<c[i].titlu<<" "<<c[i].autor<<" "<<c[i].an<<" "<<c[i].limba<<" "<<c[i].pret<<endl;
        }
        else fout<<c[i].cod<<" "<<c[i].titlu<<" "<<c[i].autor<<" "<<c[i].an<<" "<<c[i].limba<<" "<<c[i].pret<<endl;
    }
    if(Verify) cout<<"Așa cod nu există la tine în listă.\n";
}
void modificareInchiriere(){
int nr,o=1;
    cin>>nr;
    ifstream fin("Rent.txt");
    Inchiriere c[100];
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    bool Verify=true;
    ofstream fout("Rent.txt", ios::out);
    for(int i=1; i<o; i++){
        if(i==nr){
            Verify=false;
           int optiune;
            do {
            cout<<"✴Selectați ce doriți să modificați\n";
            cout<<"1. Codul\n"<<"2. Numele\n"<<"3. Prenumele\n"<<"4. Data Inchirierii\n"<<"5. Termenul Inchirierii\n"<<"6. Iesire\n";
            cin>>optiune;
            switch(optiune){
                case 1: cin>>c[i].cod_carte;
                break;
                case 2: cin>>c[i].nume;
                break;
                case 3: cin>>c[i].prenume;
                break;
                case 4: cin>>c[i].ziua>>c[i].luna>>c[i].anul;
                break;
                case 5: cin>>c[i].ziua_termen>>c[i].luna_termen>>c[i].anul_termen;
                break;
                case 6: continue;
                break;
                default: cout<<"Nu există așa opțiune. Reîncercați.\n";
                break;
            }
            } while (optiune!=6);
            fout<<c[i].cod_carte<<" "<<c[i].nume<<" "<<c[i].prenume<<" "<<c[i].ziua<<" "<<c[i].luna<<" "<<c[i].anul<<" "<<c[i].ziua_termen<<" "<<c[i].luna_termen<<" "<<c[i].anul_termen<<endl;
        }
    else fout<<c[i].cod_carte<<" "<<c[i].nume<<" "<<c[i].prenume<<" "<<c[i].ziua<<" "<<c[i].luna<<" "<<c[i].anul<<" "<<c[i].ziua_termen<<" "<<c[i].luna_termen<<" "<<c[i].anul_termen<<endl;
    }
    if(Verify) cout<<"Nu ai nicio închiriere cu așa număr de ordine";
}
void generareExpire(){
    int anul_al,luna_al,ziua_al,o=1;
    ifstream fin("Rent.txt");
    Inchiriere c[100];
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    ofstream fout("Expire.txt", ios::out);
    cout<<"✸ Introduceți datele:";
    cin>>ziua_al>>luna_al>>anul_al;
    while (anul_al>2026 || luna_al>12 || ziua_al>30 || luna_al<1 || ziua_al<1 || anul_al<1){
        cout<<"A fost introdusă o dată nevalidă, încercați din nou\n";
        cin>>ziua_al>>luna_al>>anul_al;
    }
    for (int i=1; i<o; i++){
        if(anul_al>c[i].anul_termen || (ziua_al>c[i].ziua_termen && luna_al==c[i].luna_termen && anul_al==c[i].anul_termen) || (luna_al>c[i].luna_termen && anul_al==c[i].anul_termen && ziua_al==c[i].ziua_termen ))
        fout<<c[i].cod_carte<<" "<<c[i].nume<<" "<<c[i].prenume<<" "<<c[i].ziua<<" "<<c[i].luna<<" "<<c[i].anul<<" "<<c[i].ziua_termen<<" "<<c[i].luna_termen<<" "<<c[i].anul_termen<<endl;
    }
}
void afisareCartiInchiriateAlfabetic(){
int o=1, x=1, r=1;
string codaux;
    ifstream fin("Rent.txt");
    ifstream f("Book.txt");
    Carte a[100], cartisortate[100];
    Inchiriere c[100];
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    while (f>>a[r].cod>>a[r].titlu>>a[r].autor>>a[r].an>>a[r].limba>>a[r].pret){ 
        r++;
    }
   for(int i=1; i<o; i++)
{
    codaux=c[i].cod_carte;

    for(int j=1; j<r; j++)
    {
        if(codaux==a[j].cod)
        {
            bool exista=false;

            for(int k=1; k<x; k++)
            {
                if(cartisortate[k].cod==a[j].cod)
                {
                    exista=true;
                    break;
                }
            }

            if(!exista)
            {
                cartisortate[x]=a[j];
                x++;
            }
            break;
        }
    }
}
    int aux;
   string aux2;
   for(int i=1; i<x-1; i++)
{
for(int j=i+1; j<x; j++) //insertion sort
if(cartisortate[i].titlu>cartisortate[j].titlu)
{ aux2=cartisortate[i].cod;
  cartisortate[i].cod=cartisortate[j].cod;
  cartisortate[j].cod=aux2;
  aux2=cartisortate[i].titlu;
  cartisortate[i].titlu=cartisortate[j].titlu;
  cartisortate[j].titlu=aux2;
  aux2=cartisortate[i].autor;
  cartisortate[i].autor=cartisortate[j].autor;
  cartisortate[j].autor=aux2;
  aux=cartisortate[i].an;
  cartisortate[i].an=cartisortate[j].an;
  cartisortate[j].an=aux;
  aux2=cartisortate[i].limba;
  cartisortate[i].limba=cartisortate[j].limba;
  cartisortate[j].limba=aux2; 
  aux=cartisortate[i].pret;
  cartisortate[i].pret=cartisortate[j].pret;
  cartisortate[j].pret=aux;
} }

for(int i=1; i<x; i++)
cout<<cartisortate[i].cod<<setw(31)<<cartisortate[i].titlu<<setw(20)<<cartisortate[i].autor<<setw(8)<<cartisortate[i].an<<setw(10)<<cartisortate[i].limba<<setw(8)<<cartisortate[i].pret<<endl;
}
void ceaMaiPopularaCarte() {
    int o=1, nr_inchirieri=0, r=1, ma=0, indexul=-1;
    ifstream fin("Rent.txt");
    ifstream f("Book.txt");
    Carte a[100];
    Inchiriere c[100];
    while (fin>>c[o].cod_carte>>c[o].nume>>c[o].prenume>>c[o].ziua>>c[o].luna>>c[o].anul>>c[o].ziua_termen>>c[o].luna_termen>>c[o].anul_termen){
        o++;
    }
    while (f>>a[r].cod>>a[r].titlu>>a[r].autor>>a[r].an>>a[r].limba>>a[r].pret){
        r++;
    }
    
   for(int i=1; i<r; i++){
    for(int j=1; j<o; j++)
    {
        if(a[i].cod==c[j].cod_carte){
        nr_inchirieri++;
        }
    }
    if(ma<nr_inchirieri){
        ma=nr_inchirieri;
        indexul=i;
        }
        nr_inchirieri=0;
}
cout<<a[indexul].titlu<<endl;
}

void pretMediuLimba(){
    int o=1;
    float stotal=0, p=0;
    string limba_spec;
    cin>>limba_spec;
    ifstream fin("Book.txt");
    Carte c[100];
    while (fin>>c[o].cod>>c[o].titlu>>c[o].autor>>c[o].an>>c[o].limba>>c[o].pret){
        o++;
    }
    for (int i=1; i<o; i++){
        if(c[i].limba==limba_spec){
            stotal+=c[i].pret;
            p++;
        }
    }
    cout<<"Prețul mediu al cărților cu limba specificată este: "<<fixed<<setprecision(2)<<stotal/p<<" lei"<<endl;
}
