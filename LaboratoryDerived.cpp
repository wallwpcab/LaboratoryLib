#include "pch.h"

#include <string>

#include "Polygon.h"
#include "LaboratoryFactory.h"
#include "LaboratoryFactory1.h"
#include "LaboratoryFactory2.h"
#include "LaboratoryDerived.h"

using namespace std;

/**
 * Constructor
 * @param imagesDir the image directory
 */
LaboratoryDerived::LaboratoryDerived(std::wstring imagesDir) : mImagesDir(imagesDir)
{
    // Setting the default laboratory number
    SetLaboratoryNumber(1);

}

/**
 * Draws the laboratory
 * @param graphics the graphics to draw on
 */
void LaboratoryDerived::DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics)
{
    mActualLaboratory->Draw(graphics, mPosition.x, mPosition.y);
}

/**
 * Sets the laboratory frame
 * @param frame the given frame
 */
void LaboratoryDerived::SetLaboratoryFrame(int frame)
{
    mTime = frame / mFrameRate;
    mActualLaboratory->SetTime(mTime);
}

/**
 * Sets the laboratory as required
 * @param laboratoryNumber the laboratory number
 */
void LaboratoryDerived::SetLaboratoryNumber(int laboratoryNumber)
{
    // If laboratory number is not 2
    if (laboratoryNumber != 2) {
        mLaboratoryNumber = 1;
        LaboratoryFactory1 factory1(mImagesDir);

        mActualLaboratory = factory1.CreateLaboratory1();

        mActualLaboratory->SetLaboratoryActual(this);
    }
    // if laboratory number is 2
    else
    {
        mLaboratoryNumber = 2;

        LaboratoryFactory2 factory2(mImagesDir);

        mActualLaboratory = factory2.CreateLaboratory2();

        mActualLaboratory->SetLaboratoryActual(this);
    }

}

/**
 * Getter for the laboratory number
 * @return the laboratory number
 */
int LaboratoryDerived::GetLaboratoryNumber()
{
    return mLaboratoryNumber;
}


