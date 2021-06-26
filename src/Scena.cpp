#include "Scena.hh"

using std :: cout;
using std :: endl;
using std :: string;
using std:: make_shared;
using std :: list;
using std:: shared_ptr;

Scena::Scena() {
  zbiur();
  Lacze.ZmienTrybRys(PzG::TR_3D);
  nr_elem = 0;
  nr_drona = 0;
  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Wektor3D wym_dna(tab_wym);
  dno = new Plaszczyzna(wym_dna, 20);
  Wektor3D srodekSymetri;
  bool kolizja = false;
  for (int i = 0; i < 5 ; i++)
  {   
    
    srodekSymetri[0] = rand() % 400 - 200;
    srodekSymetri[1] = rand() % 400 - 200;
    srodekSymetri[2] = 50;
    int nr_p = rand() % 3;
    if (nr_p == 0)
      Lista_elementow.push_front(make_shared<Gora>(srodekSymetri, 100, 50, 100, "Gora" + i ));
    else if (nr_p == 1)
      Lista_elementow.push_front(make_shared<Plaskowyz>(srodekSymetri, 100, 50, 100, "Plaskowyz" + i ));
    else if (nr_p == 2)
      Lista_elementow.push_front(make_shared<Gran>(srodekSymetri, 100, 50, 100, "Graniastoslup" + i ));
    nr_elem++;
    for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_elementow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_elementow.erase(Lista_elementow.begin());
      cout << " kolizja " <<endl;
    }
    kolizja = false;
  }
  for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_nazwa().c_str());
    (*a)->zapisz();
    cout << (*a)->get_nazwa() << " " << (*a)->promien() << " " << (*a) ->get_srodek() << endl;
  }

  Lacze.DodajNazwePliku(dno->get_nazwa().c_str());
  dno->zapisz();
  kolizja = false;
  for (int i = 0; i < N; i++)
  {
    double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

    Lista_Dronow.push_front(make_shared<Dron>(i, Lacze, Wektor3D(pozycja)));

    for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_Dronow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_Dronow.erase(Lista_Dronow.begin());
    }
    else
    {
      Lista_elementow.push_front(*Lista_Dronow.begin());
      cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
      (*Lista_Dronow.begin())->zapisz();
      nr_drona++;
    }
    kolizja = false;
  }

  Lacze.Rysuj();
}
void Scena::rysuj()
{

  Lacze.Rysuj();
}
void Scena::zbiur() {
     cout << endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl 
              << " *                                               *" << endl
              << " *               Lista Elementow                 *" << endl  
              << " *                                               *" << endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;  
            
}
void Scena::Menu() {
     cout << endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl 
              << " *                    Menu                       *" << endl
              << " *       1   -   Drony                           *" << endl  
              << " *       2   -   Dodaj Element                   *" << endl           
              << " *       3   -   Usun Element                    *" << endl
              << " *       4   -   Usun Drona                      *" << endl
              << " *                                               *" << endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;  
              
 cout << " Podaj numer: " << endl;
}

bool Scena::interfejs()
{
  Menu();
  int opcja;
  cin >> opcja;
  switch (opcja)
  {
  case 1:
  {
    cout << " Wybierz drona  " << endl;
    for (int i = 0; i < (int)Lista_Dronow.size(); i++)
    {
      cout << " * " << i << endl;
    }

    int nr;
    cin >> nr;
    list<shared_ptr<Dron>>::const_iterator a;
    a = Lista_Dronow.begin();
    for (int i = 0; i < nr; i++)
    {
      a++;
    }

    (*a)->sterowanie(Lista_elementow);
  }
  break;
  case 2:
  {
    cout      << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl 
              << " *                    Dodaj                      *" << endl
              << " *        1   -   Gora                           *" << endl  
              << " *        2   -   Plaskowyz                      *" << endl           
              << " *        3   -   Graniastosłup                  *" << endl
              << " *        4   -   Dron                           *" << endl
              << " *                                               *" << endl
              << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl; 

    int nr;
    cin >> nr;
    Wektor3D srodekSymetri;

       if (nr != 4)
    {
      for (int i = 0; i < 50; i++)
      {
        srodekSymetri[0] = rand() % 400 - 200;
        srodekSymetri[1] = rand() % 400 - 200;
        srodekSymetri[2] = 50;
        bool kolizja = false;
        if (nr == 1)
        {
        Lista_elementow.push_front(make_shared<Gora>(srodekSymetri, 100, 50, 100, "Gora" + i + Lista_elementow.size() ));}
        
        if (nr == 2)
        {
          Lista_elementow.push_front(make_shared<Plaskowyz>(srodekSymetri, 100, 50, 100, "Plaskowyz" + i + Lista_elementow.size()));}
        
        if (nr == 3)
        {
          Lista_elementow.push_front(make_shared<Gran>(srodekSymetri, 100, 50, 100, "Graniastoslup" + i + Lista_elementow.size()));}
        

        nr_elem++;
        for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_elementow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {
          i--;
          Lista_elementow.erase(Lista_elementow.begin());
        }
        else
        {
          break;
        }
      }
      (*Lista_elementow.begin())->zapisz();
      Lacze.DodajNazwePliku((*Lista_elementow.begin())->get_nazwa().c_str());
    }
    else
    {
      bool kolizja = false;
      for (int i = 0; i < 50; i++)
      {
        double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        Lista_Dronow.push_front(make_shared<Dron>(nr_drona, Lacze, Wektor3D(pozycja)));

        for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_Dronow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {

          Lista_Dronow.erase(Lista_Dronow.begin());
        }
        else
        {
          Lista_elementow.push_front(*Lista_Dronow.begin());
          cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
          (*Lista_Dronow.begin())->zapisz();
          nr_drona++;
          break;
        }
        kolizja = false;
      }
        
    }
  }

  break;
  case 3:
  {
    int i = 0;
    for (list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      cout<<" * "<< i << endl;
      i++;
    }
    cout << "Podaj numer przeszkody:" << endl;

    int nr;
    cin >> nr;
    list<shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    Lacze.UsunNazwePliku((*a)->get_nazwa());
    Lista_elementow.erase(a);

        cout << "************************" << endl
             << "*  Dodano przeszkode   *" << endl
             << "************************" << endl;
  }
  break;

  case 4:
  {
    int i = 0;
    for (list<shared_ptr<Dron>>::const_iterator a = Lista_Dronow.begin(); a != Lista_Dronow.end(); a++)
    {
      cout<<" * "<< i << endl;
      i++;
    }
    cout << "Podaj numer drona:" << endl;

    int nr;
    cin >> nr;
    list<shared_ptr<Dron>>::const_iterator a = Lista_Dronow.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    (*a)->usun();

    for (list<shared_ptr<Obiekt_Sceny>>::const_iterator b = Lista_elementow.begin(); b != Lista_elementow.end(); b++)
    {
      if (*a == *b)
      {
        Lista_elementow.erase(b);
        break;
      }
    }
    Lista_Dronow.erase(a);  

        cout << "*********************" << endl
             << "*  Usunięto drona   *" << endl
             << "*********************" << endl;
         
   
  }
  break;

  default:
    break;
  }

  return true;
}

Scena::~Scena()
{
  free(dno);
}