# blockchain

## install

```
pip install conan
```

```bash
$ gcc --version
gcc (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609

conan install -s compiler=gcc -s compiler.version=5.4 -s compiler.libcxx=libstdc++11 --build=missing .

cmake .

make 
```
