#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
    public:

    //konstruktor domyslny
    ResourceManager(){rm = new Resource;}

    //destruktor
    ~ResourceManager(){delete rm;}

    //konstruktor kopiujacy
    ResourceManager(const ResourceManager& crm)
    {
      rm = new Resource;
      *rm = crm.rm;
    }

    //konstruktor przenoszenia
    ResourceManager(ResourceManager&& mrm)
    {
      rm = std::move(mrm.rm);
      mrm.rm = nullptr;
    }

    //operator przypisania
    ResourceManager& operator=(const ResourceManager& mrm)
    {
      if(!(rm == nullptr)) delete rm;
      rm = new Resource;
      *rm = mrm.rm;
      return *this;
    }

    //przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&& mrm)
    {
      if(&mrm == this)
        return *this;
      else if (!(rm == nullptr))
        delete rm;

      rm = std::move(mrm.rm);
      mrm.rm = nullptr;
      return *this;
    }

    //funkcja double get
    double get() {return rm->get();}

    private:
    Resource* rm = nullptr;
};
