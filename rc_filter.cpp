// Automatically generated C++ file on Fri May  3 19:20:56 2024
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD rc_filter.cpp kernel32.lib


#include <cmath>

double
Vik=0,          // current input voltage sample
Vik_1=0,        // previous input voltage sample
Vok=0,          // current output voltage sample
Vok_1=0;        // previous output voltage sample


union uData
{
   bool b;
   char c;
   unsigned char uc;
   short s;
   unsigned short us;
   int i;
   unsigned int ui;
   float f;
   double d;
   long long int i64;
   unsigned long long int ui64;
   char *str;
   unsigned char *bytes;
};

// int DllMain() must exist and return 1 for a process to load the .DLL
// See https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain for more information.
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef in0
#undef in1
#undef in2
#undef in3
#undef out0
#undef out1
#undef out2
#undef out3

extern "C" __declspec(dllexport) void rc_filter(void **opaque, double t, union uData *data)
{
   double  in0  = data[ 0].d; // input
   double  in1  = data[ 1].d; // input
   double  in2  = data[ 2].d; // input
   double  in3  = data[ 3].d; // input
   double  w0   = data[ 4].d; // input parameter
   double  Tsp  = data[ 5].d; // input parameter
   double &out0 = data[6].d; // output
   double &out1 = data[7].d; // output
   double &out2 = data[8].d; // output
   double &out3 = data[9].d; // output

// Implement module evaluation code here:

      // CLK is at in1


      if ((in1>0.999)&&(in1<=1.001))  {

                                       Vok_1=  Vok;        // save previous Output Voltage sample
                                       Vik_1=  Vik;        // save previous Input Voltage sample
                                       Vik=  in0;          // load current input voltage sample

                                       // calculate current output voltage sample

                                       Vok= exp(-w0*Tsp)*Vok_1 + (1- exp(-w0*Tsp))*Vik_1  ;


                                       }


   out0=Vok;
   out1=Vik;
   out2=Vok_1;
   out3=Vik_1;

}
