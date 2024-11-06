# Keypop Reader C++ API
## Overview
This repository contains C++ source files that define component interfaces aligned with the **Terminal Reader**
specifications proposed by the 
[Calypso Networks Association](https://terminal-api.calypsonet.org/specifications/reader-layer/reader-api/). This C++ 
interface is a port of the [Keypop Reader Java API](https://github.com/eclipse/keypop-reader-java-api), which remains 
the primary reference implementation. The C++ version aims to closely follow and maintain compatibility with the Java 
version, ensuring consistent functionality and adherence to the established specifications.

The focus of this project is on providing interface definitions necessary for managing readers, reader events, and card
selection mechanisms. These interfaces act as a foundational layer that can be extended and customized to suit specific
application needs.

While the codebase primarily consists of header files, some `.cpp` files are included for internal consistency testing
and validation.

## Key Characteristics
- **Interface-Driven Design**: The main source files define structures and interfaces. Concrete implementations can be
  provided by developers as per their specific requirements.
- **Modular Interfaces**: Designed to support modular extensions, allowing developers to implement custom functionality
  while adhering to the standardized interface structure defined by this project.
- **Compliance**: Aligned with the specifications of the Calypso Networks Association, ensuring that implementations
  conform to recognized standards, which is crucial for terminal reader system certification.

## Usage
To use the interface definitions in your project, include the relevant headers in your source files and provide concrete
implementations of the defined interfaces as needed.

## Documentation & Contribution Guide
The full documentation, including the **UML diagrams** and **design guide**, is available
on the [Keypop website](https://keypop.org/apis/reader-layer/reader-api/).

### Contributing
Refer to the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines on how to contribute. Please adhere to
the [Code of Conduct](CODE_OF_CONDUCT.md) when participating in this project.

## License
This project is licensed under the [MIT License](LICENSE). For more details, please refer to the [LICENSE](LICENSE)
file.