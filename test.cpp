#include <iostream>
#include <marsyas/system/MarSystemManager.h>

int main()
{
    Marsyas::MarSystemManager mng;

    Marsyas::MarSystem* net = mng.create("Series", "net");
    net->addMarSystem(mng.create("AudioSource", "src"));
    net->addMarSystem(mng.create("Spectrum", "spectrum"));
    net->addMarSystem(mng.create("PowerSpectrum", "powerspectrum"));

    net->updControl("PowerSpectrum/powerspectrum/mrs_string/spectrumType", "decibels");
    net->updControl("AudioSource/src/mrs_bool/initAudio", true);

    while (net->getctrl("AudioSource/src/mrs_bool/notEmpty")->isTrue())
    {
        std::cout << net->getctrl("mrs_realvec/processedData")->to<Marsyas::mrs_realvec>() << std::endl;
    }

    return 0;
}
