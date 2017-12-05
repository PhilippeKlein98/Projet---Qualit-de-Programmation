#ifndef MAQUETTE_H_INCLUDED
#define MAQUETTE_H_INCLUDED

class maquette
{
public:
    void licence();
    void master();

    int volumeHoraire()const;

private:
    maquette();
    vector<annee> d_va;
};

#endif // MAQUETTE_H_INCLUDED
