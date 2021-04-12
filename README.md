# philosophers
(school21 project) the basics of threading a process and how to work on the same memory space, how to make threads. You will discover the mutex, semaphore and shared memory.
---

### How to launch
There are a Makefiles in each folder.

For example:
  cd pfilo_one
  make
  ./philo_one 5 800 200 200 7
  
Parameters: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
 * number_of_philosophers: is the number of philosophers and also the number
of forks
 * time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’
milliseconds after starting his last meal or the beginning of the simulation, it
dies
 * time_to_eat: is in milliseconds and is the time it takes for a philosopher to
eat. During that time he will need to keep the two forks.
 * time_to_sleep: is in milliseconds and is the time the philosopher will spend
sleeping.
 * number_of_times_each_philosopher_must_eat: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.
