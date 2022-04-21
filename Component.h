#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H
#include "pch.h"
#include "Polygon.h"

class ActualLaboratory;
class LaboratoryDerived;

/**
 * Base class for the components of the laboratory
 */
class Component : public cse335::Polygon{
private:
    /// Position of the laboratory
    wxPoint mPosition = wxPoint(0, 0);

    /// current frame
    int mCurrentFrame = 0;

    /// Current time
    double mTime = 0.0;

    ///Working laboratory
    ActualLaboratory* mActualLaboratory;

    /// the speed of the laboratory
    double mLaboratorySpeed = 1;

public:
    Component();

    /// Destructor
    ~Component() override {}

    /// Copy constructor/disabled
    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    /**
     * Sets the position of the component
     * @param point the position
     */
    virtual void SetPosition(wxPoint point)
    {
        mPosition = point;
    }

    /**
     * Gets the position of the component
     * @return the position of the component
     */
    wxPoint GetPosition() { return mPosition; }

    virtual void Update(double time);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Sets the laboratory this component is associated with
     * @param actualLaboratory the associated laboratory
     */
    void SetLaboratory(ActualLaboratory* actualLaboratory)
    {
        mActualLaboratory = actualLaboratory;
    }

    /**
     * Getter for the time
     * @return the time
     */
    double GetTime() const
    {
        return mTime;
    }

    /**
     * Setter for the laboratory speed
     * @param speed
     */
    virtual void SetLaboratorySpeed(double speed)
    {
        mLaboratorySpeed = speed;
    }

    /**
     * Getter for the laboratory speed
     * @return the laboratory speed
     */
    virtual double GetLaboratorySpeed() const
    {
        return mLaboratorySpeed;
    }
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
