#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int N = 36;

int int_wyn = 0;
string str_crd;

struct str_pyt
{
    string pyt;
    string a;
    string b;
    string c;
    string d;
    char pop{};
} baza_pytan[N];

void vid_wcz()
{
    ifstream fst_pyt("Pytania.txt");
    string str_lin;
    int i = 0, j = 0;
    if (fst_pyt.good())
        while (!fst_pyt.eof())
        {
            getline(fst_pyt, str_lin);
            if (i == 0)
            {
                baza_pytan[j].pyt = str_lin;
                i++;
            }
            else if (i == 1)
            {
                baza_pytan[j].a = str_lin;
                i++;
            }
            else if (i == 2)
            {
                baza_pytan[j].b = str_lin;
                i++;
            }
            else if (i == 3)
            {
                baza_pytan[j].c = str_lin;
                i++;
            }
            else if (i == 4)
            {
                baza_pytan[j].d = str_lin;
                i++;
            }
            else
            {
                baza_pytan[j].pop = str_lin[0];
                i=0;
                j++;
            }
        }
    else
        cout << "error -1 file Pytania.txt not good";
    fst_pyt.close();
}

void vid_wyn()
{
    string str_tbl;
    ofstream fst_wyn("Wyniki.txt", ios::app);
    if(fst_wyn.good())
    {
        fst_wyn << endl << str_crd << " z wynikiem: " << int_wyn;
    }
    else
        cout << "error -2 file Wyniki.txt not good";
    fst_wyn.close();
    ifstream fst_tab("Wyniki.txt");
    cout << endl;
    if(fst_wyn.good())
    {
        while(!fst_tab.eof())
        {
            getline(fst_tab, str_tbl);
            cout << str_tbl << endl;
        }
    }
    else
        cout << "error -3 file Wyniki.txt not good";
    fst_tab.close();
}

int main()
{
    char chr_odp;
    vid_wcz();
    cout << "Podaj imię: " << endl; getline(cin, str_crd); cout << endl;
    for(int i=0; i<N; i++)
    {
        cout << "Pytanie " << i+1 << ": " << baza_pytan[i].pyt << endl << "A:" << baza_pytan[i].a << endl << "B:" << baza_pytan[i].b << endl << "C:" << baza_pytan[i].c << endl << "D:" << baza_pytan[i].d << endl;
        cout << "Podaj odpowiedź: "; cin >> chr_odp;
        if(chr_odp == baza_pytan[i].pop)
            int_wyn++;
        chr_odp=0;
    }
    if(int_wyn<=5)
        cout << endl << "Too bad, nigdy nie idź do milionerów matole. Uzyskałeś/aś " << int_wyn << " Punktów!" << endl;
    else if(int_wyn<=30 && int_wyn>5)
        cout << endl << "Pretty average, idz do milionerów, ale nie licz na główną wygraną. Uzyskałeś/aś " << int_wyn << " Punktów." << endl;
    else if(int_wyn<=36 && int_wyn>30)
        cout << endl << "Worthy opponent, sam zabiorę Cię do studia. Uzyskałeś/aś " << int_wyn << " Punktów." << endl;
    vid_wyn();
    cout << endl << "Pytania użyte w tym programie pochodzą z polskiej edycji programu Milionerzy. Użytek do celów edukacyjnych" << endl;
    return 0;
}
