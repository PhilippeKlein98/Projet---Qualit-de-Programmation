#ifndef UECHOIX_H
#define UECHOIX_H


class UEchoix : public UE
{
    public:
        UEchoix();
        virtual ~UEchoix();

    private:
        std::vector<UE*> d_listeUE ;
};

#endif // UECHOIX_H
