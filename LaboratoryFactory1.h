#ifndef CANADIANEXPERIENCE_LABORATORYFACTORY1_H
#define CANADIANEXPERIENCE_LABORATORYFACTORY1_H
#include "pch.h"
class ActualLaboratory;

/**
 * The first laboratory class
 */
class LaboratoryFactory1 {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    LaboratoryFactory1(std::wstring imagesDir);

    std::shared_ptr<ActualLaboratory> CreateLaboratory1();
};

#endif //CANADIANEXPERIENCE_LABORATORYFACTORY1_H
