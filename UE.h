#ifndef UE_H
#define UE_H
#include<iostream>

namespace gestionUE
{
   
    class UE
    {
        public:
            UE(int ETCS , int coefficient);
            virtual ~UE() = default;
            virtual std::string code() const = 0 ;
            int coefficient() const ;
            int ECTS() const ;
            virtual std::string intitule() const = 0 ;
            virtual int nombreHeuresCM() const = 0 ;
            virtual int nombreHeuresTD() const = 0 ;
            virtual int nombreHeuresTP() const = 0 ;
            int nombreHeuresTotal() const ;
            int nombreHeuresTotalEnTD() const ;
            virtual void print(std::ostream& ost) const ;

        private:
            int d_ETCS;
            int d_coefficient ;

    };
}



#endif // UE_H
