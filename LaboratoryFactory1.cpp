#include "pch.h"

#include "LaboratoryFactory1.h"
#include "ActualLaboratory.h"
#include "Component.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"

#include "Lever.h"
#include "Shape.h"

using namespace std;

/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
LaboratoryFactory1::LaboratoryFactory1(std::wstring imagesDir) : mImagesDir(imagesDir)
{
}


/**
 * Create a laboratory object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Laboratory
 */
std::shared_ptr<ActualLaboratory> LaboratoryFactory1::CreateLaboratory1()
{
    auto laboratory = make_shared<ActualLaboratory>();

    // the base
    auto background = make_shared<Shape>();

    background->SetImage(mImagesDir + L"/images/laboratory.jpg");
    background->Rectangle(-600,0);

    laboratory->AddComponent(background);
    // the base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/images/bed.png");
    laboratory->AddComponent(base);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(wxPoint(100,-38));
    motor->SetSpeed(1.0);
    laboratory->AddComponent(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/images/transformer.png");
    gear1->SetPosition(wxPoint(100, -88));
    laboratory->AddComponent(gear1);

    motor->GetSource()->AddRotationSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Component>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(wxPoint(155, -40));
    gear2post->SetColor(wxColour(0, 128, 0));
    laboratory->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/images/light1.png");
    gear2->SetPosition(wxPoint(155,-88));
    laboratory->AddComponent(gear2);

    gear1->Drive(gear2,0.1);

    return laboratory;
}



