<!--
*** raulgotor, eink-weather-clock, twitter_handle, e-Ink based Weather Clock, WiFi Weather clock, flip-clock style, based on a e-Ink display
-->



<!-- PROJECT SHIELDS -->
<!--
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<h3 align="center">e-Ink based Weather Clock</h3>

  <p align="center">
    WiFi Weather clock, flip-clock style, based on a e-Ink display
    <br />
    <a href="https://github.com/raulgotor/eink-weather-clock"><strong>Explore the docs »</strong></a>
    <br />
    <br />

   <img class="marginauto" src="assets/clock1.png" width="400" alt="centered image"/>
   <img class="marginauto" src="assets/clock2.png" width="400" alt="centered image"/>
    <br />
    <a href="https://github.com/raulgotor/eink-weather-clock">View Demo</a>
    ·
    <a href="https://github.com/raulgotor/eink-weather-clock/issues">Report Bug</a>
    ·
    <a href="https://github.com/raulgotor/eink-weather-clock/issues">Request Feature</a>
  </p>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project


Basic features are:


### Built With

* ESP-IDF v4.4-dev-3042-g220590d599

<!-- GETTING STARTED -->
## Getting Started

### Set-up

<img height="" src="assets/connections.jpg" width="300"/>

### Installation

#### Prerequisites

- Install ESP-IDF Framework, follow the walk-through [here](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html).

#### Steps

1. Clone the repo
   ```sh
   git clone https://github.com/raulgotor/eink-weather-clock.git
   ```
   
2. cd into the repo folder and update submodules:
   ```sh
   cd eink-weather-clock && git submodule update --init --recursive
   ```

   
3. Flash the firmware into the hardware:
   ```sh
   idf.py flash
   ```

<!-- USAGE EXAMPLES -->
## Usage


### Configuring WiFi credentials


 
### Further documentation


<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/raulgotor/eink-weather-clock/issues) for a list of proposed features (and known issues).


<!-- CONTRIBUTING -->
## Contributing

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<!-- CONTACT -->
## Contact

Raúl Gotor

Project Link: [https://github.com/raulgotor/eink-weather-clock](https://github.com/raulgotor/eink-weather-clock)

<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [LVGL - Light and Versatile Graphics Library](https://lvgl.io)
* [esp32-wifi-manager](https://github.com/tonyp7/esp32-wifi-manager)
* [Embedded C Coding Standard, 2018 Michael Barr](https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf)
* [Best README template](https://github.com/othneildrew/Best-README-Template)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/raulgotor/eink-weather-clock.svg?style=for-the-badge
[contributors-url]: https://github.com/raulgotor/eink-weather-clock/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/raulgotor/eink-weather-clock.svg?style=for-the-badge
[forks-url]: https://github.com/raulgotor/eink-weather-clock/network/members
[stars-shield]: https://img.shields.io/github/stars/raulgotor/eink-weather-clock.svg?style=for-the-badge
[stars-url]: https://github.com/raulgotor/eink-weather-clock/stargazers
[issues-shield]: https://img.shields.io/github/issues/raulgotor/eink-weather-clock.svg?style=for-the-badge
[issues-url]: https://github.com/raulgotor/eink-weather-clock/issues
[license-shield]: https://img.shields.io/github/license/raulgotor/eink-weather-clock.svg?style=for-the-badge
[license-url]: https://github.com/raulgotor/eink-weather-clock/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/raulgotor
