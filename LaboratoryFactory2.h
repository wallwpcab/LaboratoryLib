#ifndef CANADIANEXPERIENCE_LABORATORYFACTORY2_H
#define CANADIANEXPERIENCE_LABORATORYFACTORY2_H
#include "pch.h"
class ActualLaboratory;

/**
 * The second laboratory factory class
 */
class LaboratoryFactory2 {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    LaboratoryFactory2(std::wstring imagesDir);

    std::shared_ptr<ActualLaboratory> CreateLaboratory2();
};

#endif //CANADIANEXPERIENCE_LABORATORYFACTORY2_H
