<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/philosophers/blob/main/resources/repo/philosopherse.png" alt="Logo" width="150" height="150">

  <p align="center">
    In this project, we learn the basics of threading a process. We see how to create threads and use mutexes.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-100-blue"/>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithms design to illustrate synchronization issues and techniques for resolving them.

Five philosophers dine together at the same table. Each philosopher has their own place at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are thinking, not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).

This project changes few things from the original problem. Besides eating and thinking, the philosophers will sleep in between. You can also define a maximum number of meals for the philosophers, that way the program can exit on a conditional that is not death of a philosopher or forceful shutdown by the user.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Clone the repo and ```make``` it to compile. Run the binary located at the /bin folder with at least 4 parameters. They are, in order, the number of philosophers sitting at the table, the time to die in milliseconds, the time to eat each meal in milliseconds and the time to sleep after the meal in milliseconds. There is a fifth optional argument the is the number of meals each philosopher has to eat before que program ends. If the fifth argument is not specified, the program will run until the user forcefully shuts it down or a philisopher dies.

Examples:
* ```./bin/philosophers 5 800 200 200 7``` - Here each philosopher will eat 7 times befero the program ends.
* ```./bin/philosophers 4 200 200 200``` - Here some philosopher will die.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html).

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmor@gmail.com

Project Link: [https://github.com/chrisdelmoro/philosophers](https://github.com/chrisdelmoro/philosophers)

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[product-screenshot]: https://github.com/chrisdelmoro/push_swap/blob/main/resources/repo/visualizer.gif
