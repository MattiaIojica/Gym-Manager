#include <bits/stdc++.h>

using namespace std;


class Abonament
{
protected:
    string m_nume_abonament;
    float m_pret;
    int m_perioada;
    static const int perioada_maxima;

public:
    Abonament(): m_nume_abonament(""), m_pret(0), m_perioada(0){}
    Abonament(string nume, float pret, int perioada): m_nume_abonament(nume), m_pret(pret), m_perioada(perioada){}
    Abonament(Abonament &ab): m_nume_abonament(ab.m_nume_abonament), m_pret(ab.m_pret), m_perioada(ab.m_perioada) {}
    virtual ~Abonament() {}


    virtual void Citire()
    {
        cout << "Citeste detaliile abonamentului: \n";
        cout << "Numele abonamentului: "; cin >> m_nume_abonament;
        cout << "Pretul abonamentului: "; cin >> m_pret;
        cout << "Durata abonamentului: "; cin >> m_perioada;
        while(m_perioada > perioada_maxima)
        {
            cout << "Durata prea mare! Durata maxima este de 12 luni. \nTe rog introdu o durata valida. \n";
            cout << "Durata abonamentului: "; cin >> m_perioada;
        }
    }

    virtual void Afisare()
    {

        cout << "Nume abonament: " << m_nume_abonament << '\n';
        cout << "Pret abonament: " << m_pret << '\n';
        cout << "Perioada abonament: " << m_perioada << '\n';
    }

    float GetPret() { return m_pret; }
    int GetPerioada() { return m_perioada; }

    Abonament& operator=(const Abonament& ab)
    {
        m_nume_abonament = ab.m_nume_abonament;
        m_pret = ab.m_pret;
        m_perioada = ab.m_perioada;
        return *this;
    }

    friend std::istream &operator>>(std::istream &in, Abonament &ab) {
        cout << "Citeste detaliile abonamentului: \n";
        cout << "Numele abonamentului: "; in >> ab.m_nume_abonament;
        cout << "Pretul abonamentului: "; in >> ab.m_pret;
        cout << "Durata abonamentului: "; in >> ab.m_perioada;

        while(ab.m_perioada > perioada_maxima)
        {
            cout << "Durata prea mare! Durata maxima este de 12 luni. \nTe rog introdu o durata valida. \n";
            cout << "Durata abonamentului: "; in >> ab.m_perioada;
        }

        cout << '\n';
        return in;
    }

     friend std::ostream &operator<<(std::ostream &out, const Abonament &ab)
     {
         out << "Numele abonamentului: " << ab.m_nume_abonament << '\n';
         out << "Pretul abonamentului: " << ab.m_pret << '\n';
         out << "Durata abonamentului: " << ab.m_perioada << '\n';

        return out;
     }

};

const int Abonament::perioada_maxima = 12;

class Abonament_Premium: public Abonament
{
    static const int reducere_maxima;
protected:
    int m_reducere;

public:
    Abonament_Premium(): m_reducere(0){}
    Abonament_Premium(Abonament &a): Abonament(a), m_reducere(0){}
    Abonament_Premium(Abonament &a, int reducere): Abonament(a), m_reducere(reducere){}
    Abonament_Premium(string nume, float pret, int perioada, int reducere):
         Abonament(nume, pret, perioada), m_reducere(reducere){}

    ~Abonament_Premium(){}

    Abonament_Premium& operator=(const Abonament_Premium& ab)
    {
        Abonament::operator=(ab);
        m_reducere = ab.m_reducere;
        return *this;
    }

    int GetReducere(){ return m_reducere; }

    static float PretRedus(const Abonament_Premium &a)
    {
        return a.m_pret * a.m_reducere / 100;
    }

    void Citire()
    {
        Abonament::Citire();
        cout << "Reducerea abonamentului: "; cin >> m_reducere;
        while(m_reducere > reducere_maxima)
        {
            cout << "Reducerea este prea mare! Reducerea maxima este de 99%. \nTe rog introdu o reducere valida. \n";
            cout << "Reducerea abonamentului: "; cin >> m_reducere;
        }
    }

    void Afisare()
    {
        Abonament::Afisare();
        cout << "Reducerea abonamentului: " << m_reducere << '\n';
    }

    friend std::istream &operator>>(std::istream &in, Abonament_Premium &ab)
    {
        cout << "Citeste detaliile abonamentului: \n";
        cout << "Numele abonamentului: "; in >> ab.m_nume_abonament;
        cout << "Pretul abonamentului: "; in >> ab.m_pret;
        cout << "Durata abonamentului: "; in >> ab.m_perioada;

        while(ab.m_perioada > perioada_maxima)
        {
            cout << "Durata prea mare! Durata maxima este de 12 luni. \nTe rog introdu o durata valida. \n";
            cout << "Durata abonamentului: "; in >> ab.m_perioada;
        }

        cout << "Reducerea abonamentului: "; in >> ab.m_reducere;

        while(ab.m_reducere > reducere_maxima)
        {
            cout << "Reducerea este prea mare! Reducerea maxima este de 99%. \nTe rog introdu o reducere valida. \n";
            cout << "Reducerea abonamentului: "; in >> ab.m_reducere;
        }

        cout << '\n';
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, Abonament_Premium &ab)
    {
        out << "Numele abonamentului: " << ab.m_nume_abonament << '\n';
        out << "Pretul abonamentului: " << ab.m_pret << '\n';
        out << "Durata abonamentului: " << ab.m_perioada << '\n';
        out << "Reducerea abonamentului: " << ab.m_reducere << '\n';

        return out;
    }
};

const int Abonament_Premium::reducere_maxima = 99;

class Persoana
{
protected:
    int m_id;
    string m_nume, m_cnp;

public:
    Persoana(): m_id(0), m_nume(""), m_cnp("") {}
    Persoana(int id, string nume, string cnp): m_id(id), m_nume(nume), m_cnp(cnp){}
    Persoana(Persoana &p): m_id(p.m_id), m_nume(p.m_nume), m_cnp(p.m_cnp) {}

    virtual ~Persoana(){}

    virtual int GetId(){ return m_id; }

    virtual void Citire()
    {
        cout << "Citeste detaliile persoanei: \n";
        cout << "Id: "; cin >> m_id;
        cout << "Nume: "; cin >> m_nume;
        cout << "Cnp: "; cin >> m_cnp;
    }

    virtual void Afisare()
    {
        cout << "Id: " << m_id << '\n';
        cout << "Nume: " << m_nume << '\n';
        cout << "Cnp: " << m_cnp << '\n';
    }

    Persoana& operator=(const Persoana& p)
    {
        m_id = p.m_id;
        m_nume = p.m_nume;
        m_cnp = p.m_cnp;
        return *this;
    }

    friend std::istream &operator>>(std::istream &in, Persoana &p)
    {
        cout << "Citeste detaliile persoanei: \n";
        cout << "Id: "; in >> p.m_id;
        cout << "Nume: "; in >> p.m_nume;
        cout << "Cnp: "; in >> p.m_cnp;
        cout << '\n';
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, Persoana &p)
    {
         out << "Id: " << p.m_id << '\n';
         out << "Nume: " << p.m_nume << '\n';
         out << "Cnp: " << p.m_cnp << '\n';
         return out;
    }

};

class Abonat: public Persoana
{
protected:
    string m_nr_telefon;
    Abonament_Premium m_x;
public:
    Abonat(): m_nr_telefon(""), m_x(){}
    Abonat(Persoana &p, string nr_telefon, Abonament_Premium &x): Persoana(p), m_nr_telefon(nr_telefon), m_x(x){}
    Abonat(int id, string nume, string cnp, string nr_telefon, Abonament_Premium &x): Persoana(id, nume, cnp), m_nr_telefon(nr_telefon), m_x(x){}

    ~Abonat(){}

    int GetId()
    {
        Persoana::GetId();
    }

    float GetPret()
    {
        m_x.Abonament_Premium::GetPret();
    }

    int GetPerioada()
    {
        m_x.Abonament_Premium::GetPerioada();
    }

    int GetReducere()
    {
        m_x.Abonament_Premium::GetReducere();
    }

    float PretRedus()
    {
        Abonament_Premium::PretRedus(m_x);
    }

    Abonament_Premium Getm_x() { return m_x; }

    void Citire()
    {
        Persoana::Citire();
        cout << "Numar de telefon: "; cin >> m_nr_telefon;
        cin >> m_x;
    }

    void Afisare()
    {
        Persoana::Afisare();
        cout << "Numar de telefon: " << m_nr_telefon << '\n';
        cout << m_x << '\n';
    }

    Abonat& operator=(const Abonat& a)
    {
        Persoana::operator=(a);
        m_nr_telefon = a.m_nr_telefon;
        m_x = a.m_x;
        return *this;
    }

    friend std::istream &operator>>(std::istream &in, Abonat &a)
    {
        cout << "Citeste detaliile abonatului: \n";
        cout << "Id: "; in >> a.m_id;
        cout << "Nume: "; in >> a.m_nume;
        cout << "Cnp: "; in >> a.m_cnp;
        cout << "Numar de telefon: "; in >> a.m_nr_telefon;
        cin >> a.m_x;
        cout << '\n';
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, Abonat &a)
     {
        out << "Id: " << a.m_id << '\n';
        out << "Nume: " << a.m_nume << '\n';
        out << "Cnp: " << a.m_cnp << '\n';
        out << "Numar de telefon: " << a.m_nr_telefon << '\n';
        out << a.m_x;

        return out;
     }
};

Abonat* CitesteAbonat()
{
    Abonat *a;

    a = new Abonat;
    a -> Citire();

    return a;
}

vector <Abonat*> citesteNAbonati()
{
    int n;
    cout << "Numarul de abonati: "; cin >> n;

    vector <Abonat*> abonati;

    for(int i = 0; i < n; i++)
    {
        abonati.push_back(CitesteAbonat());
    }

    return abonati;
}


class Clienti
{
protected:
    vector <Abonat*> abonati;
public:

    void AdaugaAbonat();
    void AdaugaNAbonati();
    void EliminareAbonatN(int n);
    void EliminareById(int id);
    void AfisareAbonati();
    int NrAbonatiPremium();
    float IncasariTotale();

    ~Clienti()
    {
        for(int i = 0; i < abonati.size(); i++)
            delete abonati[i];
    }

};

void Clienti::AdaugaAbonat()
{
    abonati.push_back(CitesteAbonat());
}

void Clienti::AdaugaNAbonati()
{
    vector <Abonat*> adauga = citesteNAbonati();
        for(int i = 0; i < adauga.size(); i++)
            abonati.push_back(adauga[i]);
}

void Clienti::EliminareAbonatN(int n)
{
    if(n <= abonati.size())
    {
    for(int i = n - 1; i < abonati.size(); i++)
    {
        abonati[i] = abonati[i + 1];
    }

    abonati.pop_back();
    }
}

void Clienti::AfisareAbonati()
{
    if(abonati.size() == 0)
        cout << "Lista este vida! \n";

    for(int i = 0; i < abonati.size(); i++)
    {
        cout << "Abonat " << i + 1 << ": \n";
        cout << *abonati[i] << '\n';
    }
}

void Clienti::EliminareById(int id)
{
    for(int i = 0; i < abonati.size(); i++)
    {
        //cout << abonati[i];
        if(abonati[i] -> GetId() == id)
        {
            for(int j = i; j < abonati.size() - 1; j++)
                abonati[j] = abonati[j + 1];
            abonati.pop_back();
            break;
        }
    }
}

int Clienti::NrAbonatiPremium()
{
    int nr = 0;
    for(int i = 0; i < abonati.size(); i++)
    {
        //abonati[i] -> Afisare();
        if(abonati[i] -> GetReducere() > 0)
            nr++;
    }
    return nr;
}

float Clienti::IncasariTotale()
{
    float suma = 0;

    for(int i = 0; i < abonati.size(); i++)
    {
        suma = suma + abonati[i] -> GetPret() * abonati[i] -> GetPerioada();
        if(abonati[i] -> GetReducere() > 0)
            suma = suma - (abonati[i] -> GetPerioada() * abonati[i] -> PretRedus());
    }

    return suma;
}



void Optiuni()
{
    cout << "1. Citeste un abonament, abonament premium, persoana sau abonat: \n";
    cout << "2. Citeste N Abonati \n";
    cout << "3. Clasa clienti \n";
    //cout << "4. Demo \n";
    cout << "9. Stop! \n \n";
}

void OptiuniSingure()
{
    cout << "Alege ce vrei sa citesti: \n";
    cout << "1. Abonament \n";
    cout << "2. Abonament Premium\n";
    cout << "3. Persoana \n";
    cout << "4. Abonat \n";
    cout << "9. Pentru a te intoarce la meniul initial \n \n";
}

void OptiuniClienti()
{
    cout << "1. Adauga un abonat listei tale \n";
    cout << "2. Adauga n abonati listei tale \n";
    cout << "3. Sterge un abonat de pe o pozitie specificata \n";
    cout << "4. Sterge un abonat dupa id-ul lui \n";
    cout << "5. Afisarea listei \n";
    cout << "6. Afisarea numarului de abonati premium \n";
    cout << "7. Afisarea incasarilor totale \n";
    cout << "9. Pentru a te intoarce la meniul initial \n \n";
}

void OptiuniDemo()
{
    cout << "Alege ce vrei sa citesti: \n";
    cout << "1. Abonament Premium\n";
    cout << "2. Abonat\n";
}

void demo()
{
    Abonament *aux = new Abonament_Premium("Gym", 150, 12, 5);

    //Abonament_Premium ab("Gym", 150, 12, 5);
    //Persoana *aux = new Abonat(123, "Ion", "50321516123165", "0742654648", ab);

    if(Abonament_Premium *abb = dynamic_cast<Abonament_Premium *>(aux))
    {
        cout << "Abonament Premium cu reducerea de " << abb -> GetReducere() << " % \n\n";
    }

    if(Abonat *abonat = dynamic_cast<Abonat *>(aux))
    {
        Abonament_Premium aaaa;
        aaaa = abonat -> Getm_x();
        cout << "Abonamentul abonatului: \n" << aaaa;
        //cout << "Abonamentul abonatului: \n" << abonat -> Getm_x() << '\n';
    }


    Abonament abo("Gym", 150, 3);
    Abonament_Premium *prem = (Abonament_Premium *) &abo;

    if(Abonament_Premium *abonament_premium = dynamic_cast <Abonament_Premium*> (prem))
        cout << "Pretul abonamentului : " << prem -> GetPret() << "\n\n";

}

void MeniuInteractiv()
{
    int comanda = 0, stop = 9;

    while(comanda != stop)
    {
        Optiuni();
        cin >> comanda;

        if(comanda == 1) // ab, ab_p, pers, abonat
        {
            int cm = 0;

            while(cm != 9)
            {
                OptiuniSingure();

                cin >> cm;

                if(cm == 1)
                {
                    Abonament a;
                    cin >> a;
                    cout << a << '\n';
                }
                else if(cm == 2)
                {
                    Abonament_Premium a;
                    cin >> a;
                    cout << a << '\n';
                }
                else if(cm == 3)
                {
                    Persoana a;
                    cin >> a;
                    cout << a << '\n';
                }
                else if(cm == 4)
                {
                    Abonat a;
                    cin >> a;
                    cout << a << '\n';
                }
                else if(cm == 9)
                    break;
            }

        }
        else if(comanda == 2) // citeste n abonati
        {
            vector <Abonat*>abonati = citesteNAbonati();
            cout << "Daca doresti sa afisezi abonatii cititi, apasa 1 \n";
            int cm = 0;
            cin >> cm;
            if(cm == 1)
                for(int i = 0; i < abonati.size(); i++)
                {
                    cout << "Abonat " << i + 1 << ": \n";
                    cout << *abonati[i] << '\n';
                }
        }
        else if(comanda == 3) // clasa clienti
        {
            Clienti a;

            cout << "Tocmai ai creat o lista de abonati! \n";
            cout << "Poti modifica lista folosind urmatoarele comenzi: \n";
            OptiuniClienti();


            int cm = 0;
            while(cm != 9)
            {

                cin >> cm;

                if(cm == 0)
                    OptiuniClienti();
                else
                if(cm == 1)
                {
                    a.AdaugaAbonat();
                }
                else if(cm == 2)
                {
                    a.AdaugaNAbonati();
                }
                else if(cm == 3)
                {
                    int n;
                    cout << "Citeste pozitia abonatului pe care doresti sa-l stergi. \n";
                    cout << "! Daca numarul citit este mai mare decat numarul de abonati nu se va intampla nimic !\n";
                    cin >> n;
                    a.EliminareAbonatN(n);
                }
                else if(cm == 4)
                {
                    int id;
                    cout << "Citeste id-ul abonatului pe care doresti sa-l stergi. \n";
                    cout << "! Daca nu exista un abonat cu id-ul specificat, nu se va intampla nimic ! \n";
                    cin >> id;
                    a.EliminareById(id);
                }
                else if(cm == 5)
                {
                    a.AfisareAbonati();
                }
                else if(cm == 6)
                {
                    cout << "Numarul de abonati premium: " << a.NrAbonatiPremium() << '\n';
                }
                else if(cm == 7)
                {
                    cout << "Incasari totale: " << fixed << setprecision(2) << a.IncasariTotale() << '\n';
                }
                else
                    if(cm == 9)
                    break;


                if(cm != 0)
                    cout << "Pentru a revedea optiunile apasa tasta 0 \n";
            }


        }
        /*else if(comanda == 4)
        {
            demo();
        }*/
        else if(comanda == 9)
        {
            break;
        }

    }

}


int main()
{
    MeniuInteractiv();

    cout << "Finalul programului!";

    return 0;
}
