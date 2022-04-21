#ifndef CANADIANEXPERIENCE_ACTUALLABORATORY_H
#define CANADIANEXPERIENCE_ACTUALLABORATORY_H

#include <vector>
#include "Component.h"

class LaboratoryDerived;

/**
 * The actual laboratory with which we will work
 */
class ActualLaboratory {
private:
    /// The time of the laboratory
    double mTime = 0.0;

    /// list of components
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Laboratory Actual object
    LaboratoryDerived* mDerivedLaboratory = nullptr;

public:
    ActualLaboratory() ;

    /**
    Destructor
    */
    virtual ~ActualLaboratory() {};

    /// Copy constructor/disabled
    ActualLaboratory(const ActualLaboratory&) = delete;

    /// Assignment operator/disabled
    void operator=(const ActualLaboratory&) = delete;

    void AddComponent(const std::shared_ptr<Component>& component);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) ;

    /**
     * Sets the actual laboratory
     * @param laboratoryDerived the laboratory derived
     */
    void SetLaboratoryActual(LaboratoryDerived *laboratoryDerived)
    {
        mDerivedLaboratory = laboratoryDerived;
    }

    void SetTime(double time);

    void SetSpeed(double speed);
};

#endif //CANADIANEXPERIENCE_ACTUALLABORATORY_H
