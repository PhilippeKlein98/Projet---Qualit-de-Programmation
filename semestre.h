#ifndef SEMESTRE_H_INCLUDED
#define SEMESTRE_H_INCLUDED

class semestre
{
public:
    void addUE();
    void supUE();
    void modifUE();

    int volumeHoraire()const;

private:
    semestre();
    vector<UE> d_vue;
};

#endif // SEMESTRE_H_INCLUDED
