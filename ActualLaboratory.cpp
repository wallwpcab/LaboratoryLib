#include "pch.h"

#include <vector>
#include <memory>

#include "ActualLaboratory.h"
#include "LaboratoryDerived.h"
#include "Component.h"

using namespace std;

/**
 * Constructor
 */
ActualLaboratory::ActualLaboratory()
{

}

/**
 * Adds the component to the laboratory
 * @param component the component to be added
 */
void ActualLaboratory::AddComponent(const std::shared_ptr<Component>& component)
{
    component->SetLaboratory(this);
    mComponents.push_back(component);
}

/**
 * Draws the component of the laboratory
 * @param graphics graphics to draw on
 * @param x x position
 * @param y y position
 */
void ActualLaboratory::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, x, y);
    }
}

/**
 * Sets the time of components in the laboratory
 * @param time the given time
 */
void ActualLaboratory::SetTime(double time)
{
    mTime = time;
    for (auto component : mComponents)
    {
       component->Update(time);
    }
}

/**
 * Sets the laboratory speed
 * @param speed the speed of the laboratory
 */
void ActualLaboratory::SetSpeed(double speed)
{
    // to rotate the laboratory while speed is increasing
    for (auto component : mComponents)
    {
        component->SetLaboratorySpeed(speed);
        component->Update(mTime);
    }
}
