#ifndef ANNEE_H_INCLUDED
#define ANNEE_H_INCLUDED

class annee
{
public:
    int volumeHoraire()const;

    void modifSemestre();

private:
    annee();
    semestre d_s1, d_s2;
};

#endif // ANNEE_H_INCLUDED
