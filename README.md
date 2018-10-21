# TSU C++ labs ![version](https://img.shields.io/badge/version-1.0.0-green.svg)

Tomsk State University, Faculty of Applied Mathematics and Cybernetics, C++ laboratory works

## Usage
Currently the makefiles are broken.

### 1 semester
```shell
make -f makefiles/semester-1.makefile
```

### 2 semester

Test data: `tests/tests-data/db`

### 3 semester

N - task number

```shell
make -f makefiles/semester-1.makefile BIN=N test
```

### 4 semester

Test data: `tests/tests-data/graph.txt`

```shell
make TEST="test name" IMPORTS="list cpp exports" test -f makefiles/semester-1.makefile
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](./LICENSE)
