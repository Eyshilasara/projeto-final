#ifndef FITA_VIDEO_HPP
#define FITA_VIDEO_HPP

#include "midia.hpp"

class FitaVideo : public Midia {
protected:
        bool rebobinado;

    public:
        FitaVideo(const std::string& _tipo, const std::string& _titulo, int _codigo, const std::string& _genero, int _quantidadeTotal, int _quantidadeDisponivel, bool _rebobinado);
        
        FitaVideo(){};

        void exibirInfo() const;

        void setRebobinado(bool rebobinado) {
            this->rebobinado = rebobinado;
        }
        bool getRebobinado() const {
            return rebobinado;
        }
};

#endif 