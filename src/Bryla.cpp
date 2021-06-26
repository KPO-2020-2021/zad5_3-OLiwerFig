#include "Bryla.hh"


using std :: endl;
using std :: ios;
using std :: string;
using std :: fstream;
using std :: shared_ptr;

Wektor3D &Bryla::operator[](int index)
{
    return wierzcholek[index];
}
Wektor3D Bryla::operator[](int index) const
{
    return wierzcholek[index];
}

void Bryla::set_nazwa(string nazwa)
{
    this->nazwa = nazwa;
}

void Bryla::set_srodek(Wektor3D srodek)
{
    this->srodek = srodek;
}

Wektor3D Bryla::get_srodek() const
{
    return srodek;
}

string Bryla::get_nazwa() const
{
    return nazwa;
}

void Bryla::przesun(Wektor3D wek)
{
    for (int i = 0; i < (int)wierzcholek.size(); i++)
    {
        wierzcholek[i] = wierzcholek[i] + wek;
    }
    srodek = srodek + wek;
}

void Bryla::translacja(Macierz3x3 obr)
{
    for (int i = 0; i < (int)wierzcholek.size(); i++)
    {
        wierzcholek[i] = (obr * wierzcholek[i]);
    }
    srodek=obr*srodek;
}

void Bryla::zapisz()
{
    fstream plik;
    double tab[] = {0, 0, (*wymiary)[2] / 2};
    Wektor3D przesun_sr(tab);

    plik.open(nazwa, ios::out);

    for (int i = 0; i < (int)wierzcholek.size(); i += 2)
    {
        plik << srodek + przesun_sr << endl;
        for (int j = 0; j < 2; j++)
        {
            plik << wierzcholek[j + i] << endl;
        }
        plik << srodek - przesun_sr << endl
             << endl;
    }

    plik << srodek + przesun_sr << endl;
    for (int j = 0; j < 2; j++)
    {
        plik << wierzcholek[j] << endl;
    }
    plik << srodek - przesun_sr << endl
         << endl;
    plik.close();
}
bool Bryla::czy_kolizja(shared_ptr<Obiekt_Sceny> ob)
{
    shared_ptr<Bryla> self = shared_from_this();

    if (ob != self)
    {

        Wektor3D srodek_Bryla= get_srodek();
        Wektor3D srodek_Obiektu = ob->get_srodek();
        double l = sqrt(pow(srodek_Bryla[0] - srodek_Obiektu[0], 2) + pow(srodek_Bryla[1] - srodek_Obiektu[1], 2) + pow(srodek_Bryla[2] - srodek_Obiektu[2], 2));
        if (promien() + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}