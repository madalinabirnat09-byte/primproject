#include <fstream>
#include <iostream>
#include <optiuni.h>
using namespace std;
int main()
{
    int optiune;
    do{
    cout << "\n✦•·······•✦ MENIU BIBLIOTECA ✦•·······•✦ \n";
    cout<<"Alegeți dintre următoarele opțiuni:\n";
    cout<<" 1.Afișarea pe ecran a informației despre cărți\n ";
    cout<<"2.Afișarea pe ecran a informației despre închirieri \n ";
    
    // restrictie la luarea maxima a 3 carti
    // afisare in tabel a informatiilor
    // restrictie daca vrei sa adaugi o carte/ info that already exists
    cout<<"3.Adăugarea informației despre o carte nouă  \n";
    cout<<" 4.Adăugarea informației despre o închiriere nouă \n ";
    cout<<"5.Ștergerea informației despre o carte, al cărei cod este introdus de la tastatură \n ";
    cout<<"6.Ștergerea informației despre o închiriere, al cărei număr de ordine este introdus de la tastatură \n ";
    cout<<"7.Modificarea informației despre o carte, al cărei cod este introdus de la tastatură \n ";
    cout<<"8.Modificarea informației despre o închiriere, al cărei număr de ordine este introdus de la tastatură \n";
    cout<<" 9.Crearea fișierului text Expire.txt, care conține informații despre închirierile al căror termen a expirat \n"
        <<"la data introdusă de la tastatură \n";
    cout<<" 10.Afișarea pe ecran a listei cărților aflate la abonați, în ordine alfabetică după titlu \n";
    cout<<" 11.Afișarea pe ecran a informației despre cea mai populară carte \n";
    cout<<" 12.Afișarea pe ecran a prețului mediu al tuturor cărților pentru limba specificată \n";
    cout<<" Pentru ieșire tastați 0\n";
    cout << "Alegeți: "; cin >> optiune;
    if(!cin){
    cout<<"Opțiunea nu e validă. Reîncercați.\n";
    while(!cin){
        cin>>optiune;
    } }
        switch(optiune){
            case 1: afisareCarti();  break;
            case 2: afisareInchirieri();  break;
            case 3: { cout<<"🟆 Introduceți informațiile cărții "<<endl;
                               adaugareCarte(); break;}
            case 4: { cout<<"🟆 Introduceți informațiile despre închiriere"<<endl;
                               adaugareInchiriere();  break;}
            case 5: { cout<<"🟆 Introduceți codul cărții pe care doriți să o ștergeți: ";
                               stergereCarte();  break;}
            case 6: { cout<<"🟆 Introduceți numărul de ordine al închirierii pe care doriți să o ștergeti: ";
                               stergereInchiriere(); break;}
            case 7: modificareCarte(); break;
            case 8: modificareInchiriere();  break;
            case 9:  generareExpire(); break;
            case 10: { cout<<"🟆 Cărțile închiriate în ordine alfabetică: \n";
                               afisareCartiInchiriateAlfabetic();  break;
            case 11: { cout<<"🟆 Cea mai populară carte este: ";
                                ceaMaiPopularaCarte();  break; }
            case 12: { cout<<"🟆 Introduceți limba dorită: ";
                                pretMediuLimba();  break; }
        } } }while(optiune !=0);
return 0;}