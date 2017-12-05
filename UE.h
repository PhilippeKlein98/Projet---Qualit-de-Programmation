#ifndef UE_H_INCLUDED
#define UE_H_INCLUDED

class UE : public ecue
{
public:
    int nbrHeure()const;

    void afficheMatieres()const;
    void addMatiere();
    void supMatiere(const string & nomMatiere);
    void modifMatiere();

    void modifInfos();

private:
    UE();
    vector<ecue> d_ve;
    int d_nbrECTS, d_coef;
};

#endif // UE_H_INCLUDED
