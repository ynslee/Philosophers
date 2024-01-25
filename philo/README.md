<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p>

<h3 align="center">Philosophers</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/issues)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Few lines describing your project.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

Solving threads' concurrent and deadlock problem using mutexes

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

```
Git clone the repository 
```

### Installing


```
$make
$./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
##### 1\. `number_of_philosophers` : N numbers of philosophers(n amount of forks)

##### 2\. `time_to_die` : Philosopher will die under this circumstance(ms)

-  After the simulation started, if the philosopher doesnt eat wihtin `time_to_die`ms after the last meal

##### 3\. `time_to_eat` : The amount of time(ms) it takes for the philosopher to eat

-   while eating, one philosopher needs two forks(its left side and right side)

##### 4\. `time_to_sleep` : The amount of time(ms) it takes for the philosopher to sleep

##### 5\. `number_of_times_each_philosopher_must_eat` (optionable choice)

-   Simulation stops when all the philosophers eat Nth amount of time
-   If this is not given, simulation should only stop when one of the philosopher dies

## 🔧 Running the tests <a name = "Conditions for it to run"></a>

```
0 < number_of_philosophers < 200 || time_to_die > 60 || time_to_eat > 60 || time_to_sleep > 60
```
### In case if you don't want any philosophers to die
 
 - If the number of philsopher is odd, it should be more than 1 philosopher, time to die should be triple the amount of time to eat, time to sleep.
```
$./philo 3 510 200 200
```
 - If the number of philsopher is even, it should be more than 1 philosopher, time to die should be triple the amount of time to eat, time to sleep.
```
$./philo 4 410 200 200

```