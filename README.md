# L2-sim
### Author: Bc. Adam Pap

### Build
In order to build and compile the program, you need to use the **build_me.sh** which is located in the root folder of the project. This script automatically creates the `/build` folder, if there is none and places there the executable file. 

When you are in the the root folder just run this command:
 ```
bash build_me.sh
 ```

After this step done you can run the program by using this command:
 ```
bash parser.sh file1.txt file2.bin file3.json file4.txt
 ```

Eventually you can do it manually:

(create the `/build` folder if it does not exists by using **mkdir build** command)
 ```
mkdir build
cd build
cmake ..
make
 ```


