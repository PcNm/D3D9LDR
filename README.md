# D3D9LDR
Header-Only Direct3D 9.0c Loader &amp; Wrapper For C &amp; C++ in clean C

- #### REQUIRES [HARDFORM.H](https://github.com/PcNm/HARDFORM), [DYNALOAD.H](https://github.com/PcNm/DYNALOAD)

### USAGE
```c
#include "D3D9LDR.H"
```
wherever you want it in your code, but you'll also need to 
```c
#define D3D9LDR_IMPLEMENTATION
```
before including the header file in *one* C or C++ file to create the implementation.
<br>
```c
// One of your source files should have something that may look like this
#include ...  
#include ...  
#define D3D9LDR_IMPLEMENTATION  
#include "D3D9LDR.H"  
```
For more documentation, check out the header files and the sample code.
<br><br>
*That's it! Enjoy implementing your Direct3D 9.0c render pipeline.*
<br>

#### STATUS
Version: **1.0** <br>
Platforms supported: Windows. <br>
Has been tested with: VS2017, GCC. <br>
<br>
