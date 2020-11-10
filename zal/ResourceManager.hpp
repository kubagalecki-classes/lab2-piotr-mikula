#pragma once

#include "Resource.hpp"

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
      rm = new Resource{*crm.rm};
    }
    //konstruktor przenoszenia
    ResourceManager(ResourceManager&& mrm)
    {
      //rm = std::move(mrm.rm);
      rm = mrm.rm;
      mrm.rm = nullptr;
    }

    //operator przypisania
    ResourceManager& operator=(const ResourceManager& mrm)
    {
      if(this != &mrm) 
      {
        delete rm;
        rm = new Resource{*mrm.rm};
        //mrm.rm = nullptr;
      }
      return *this;
    }

    //przenoszący operator przypisania
    ResourceManager& operator=(ResourceManager&& mrm)
    {
      //if(&mrm == this)
      //  return *this;
      //else if (!(rm == nullptr))
      //  delete rm;
      if(this != &mrm)
      {
        delete rm;
        rm = mrm.rm;
        mrm.rm = nullptr;
      }

      //rm = std::move(mrm.rm);
      //mrm.rm = nullptr;
      return *this;
    }

    //funkcja double get
    double get() {return rm->get();}

    private:
    Resource* rm = nullptr;
};
