#ifndef CANADIANEXPERIENCE_LABORATORYDERIVED_H
#define CANADIANEXPERIENCE_LABORATORYDERIVED_H
#include "pch.h"
#include "Laboratory.h"
#include <vector>
#include <string>
#include <memory>
#include "Component.h"
#include "ActualLaboratory.h"

/**
 * The derive laboratory we will have
 */
class LaboratoryDerived final : public Laboratory  {
private:
    /// Current Time
    double mTime = 0.0;

    ///Current Laboratory number
    int mLaboratoryNumber = 1;

    /// Current Laboratory Number
    std::shared_ptr <ActualLaboratory> mActualLaboratory = nullptr;

    /// the image directory of the laboratory
    std::wstring mImagesDir;

    /// the laboratory speed
    double mLaboratorySpeed;

    /// The frame rate
    double mFrameRate = 30;

    /// The laboratory's location
    wxPoint mPosition = wxPoint(0,0);

public:
    LaboratoryDerived(std::wstring imagesDir);

    /// Destructor
    ~LaboratoryDerived() override {}

    /// Copy constructor/disabled
    LaboratoryDerived(const LaboratoryDerived&) = delete;

    /// Assignment operator/disabled
    void operator=(const LaboratoryDerived&) = delete;

    void DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics) override;

     void SetLaboratoryFrame(int frame) override;

     void SetLaboratoryNumber(int laboratoryNumber) override;

     int GetLaboratoryNumber() override;

    /**
     * Sets the speed of the laboratory
     * @param speed the laboratory speed
     */
    void SetSpeed(double speed)
    {
        mLaboratorySpeed = speed;
        mActualLaboratory->SetSpeed(speed);
    }

    /**
     * Getter for the laboratory time
     * @return the laboratory time
     */
    double GetLaboratoryTime() override
    {
        return mTime;
    }

    /**
     * Setter for the frame rate
     * @param frameRate the frame rate
     */
    void SetFrameRate(double frameRate) override
    {
        mFrameRate = frameRate;
    }

    /**
     * Setter for the location
     * @param position the position of the laboratory
     */
    void SetLocation(wxPoint position)
    {
        mPosition = position;
    }

};

#endif //CANADIANEXPERIENCE_LABORATORYDERIVED_H
