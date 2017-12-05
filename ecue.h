#ifndef ECUE_H_INCLUDED
#define ECUE_H_INCLUDED

class ecue
{
public:
    const string& code()const;
    const string& nom()const;
    int nbrHcours()const;
    int nbrHTD()const;
    int nbrHTP()const;

    int nbrHeure()const;
    void modifInfos();
    void afficheInfos()const;

private:
    ecue();
    int d_nbrHcours, d_nbrHTD, d_nbrHTP;
    string d_code;
    string d_nom;
};

#endif // ECUE_H_INCLUDED
