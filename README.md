# L2-sim
### Author: Adam Pap

### Build
In order to build and compile the program, you need to use the **build_me.sh** which is located in the root folder of the project. This script automatically create the `/build` folder, (if there is none) then compile the program, and install the project into your `/home` directory.

When you are in the the root folder of the project, just run this command:
 ```
bash build_me.sh
 ```

After this step done, you can run the program by using the next command:
 ```
bash ~/L2_sim/scripts/parser.sh file1.txt file2.bin file3.json file4.txt
 ```

Eventually you can do it manually:

(create the `/build` folder if it does not exists by using **mkdir build** command)
 ```
mkdir build
cd build
cmake ..
make install
 ```

\
If you do not wish to install the project then you can follow these steps:
 ```
mkdir build
cd build
cmake ..
make
 ```

And then run the script **parser.sh** located in the `/scripts` folder:
 ```
cd scripts
bash parser.sh file1.txt file2.bin file3.json file4.txt
 ```

This will create the build files in the build directory, compile the project, but it won't install it into your system. You can then run the program directly from the `/build` directory.

#### ***Important note***
After the installation proccess to the `/home` folder, the files which are going to be processed e.g. **file1.txt file2.bin file3.json file4.txt** must be in the same folder as the **parser.sh** script ! Otherwise the C++ program will not be able to resolve the paths to the files when you run the program (by using script **parser.sh**) from the different folder than the `/home`. This is because the C++ program expects relative paths to the files.

### Resources
https://stackoverflow.com/questions/6361606/save-argv-to-vector-or-string

https://stackoverflow.com/questions/12733888/regarding-c-include-another-class

https://www.geeksforgeeks.org/factory-method-pattern-c-design-patterns/

https://www.geeksforgeeks.org/std-future-in-cpp/

https://stackoverflow.com/questions/12876361/reading-bytes-in-c

https://github.com/nlohmann/json

https://stackoverflow.com/questions/7336096/python-glob-without-the-whole-path-only-the-filename




***
\
\
Автор: Адам Пап 

Сборка
Для сборки и компиляции программы необходимо использовать скрипт **build_me.sh**, который находится в корневой папке проекта. Этот скрипт автоматически создаст папку `/build` (если ее нет), затем скомпилирует программу и установит проект в каталог `/home`.

Когда вы окажетесь в корневой папке проекта, просто выполните эту команду:
 ```
bash build_me.sh
 ```

После выполнения этого шага вы можете запустить программу, используя следующую команду:
 ```
bash ~/L2_sim/scripts/parser.sh file1.txt file2.bin file3.json file4.txt
 ```

В конце концов вы сможете сделать это вручную:
(создайте папку `/build`, если она не существует, с помощью команды **mkdir build**)
```
mkdir build
cd build
cmake ..
make install
```

\
Если вы не хотите устанавливать проект, то можете выполнить следующие шаги:
 ```
mkdir build
cd build
cmake ..
make
 ```

Затем запустите скрипт **parser.sh**, расположенный в папке `/scripts`:
 ```
cd scripts
bash parser.sh file1.txt file2.bin file3.json file4.txt
 ```

Это создаст файлы сборки в каталоге build, скомпилирует проект, но не установит его в вашу систему. Вы можете запустить программу прямо из каталога `/build`.

#### ***Важное замечание***.
После установки в папку `/home` файлы, которые будут обрабатываться, например, **file1.txt file2.bin file3.json file4.txt** должны находиться в той же папке, что и скрипт **parser.sh** ! В противном случае программа на C++ не сможет определить пути к файлам, если вы запустите программу (с помощью скрипта **parser.sh**) из папки, отличной от `/home`. Это происходит потому, что программа на C++ ожидает относительных путей к файлам.