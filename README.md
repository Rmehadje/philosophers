# DINING PHILOSOPHERS

The dining philosophers problem is a famous computing problem in concurrency, it describes a round table filled with a certain number of philosophers, where they spend their life time as a philosopher should: eating, sleeping and thinking.

each philosopher needs two forks to eat, one on his left, the other on his right, when one is not eating he is either sleeping or thinking, with a timer that dictates how long they could go without eating, if the timer reaches 0 for any philosopher, they meet their doom.

the point of this project is to find a way where every philosopher is able to eat sleep and think in harmony without anyone perishing, of course that is, within certain logical limits.

the implementation is in C, and it takes advantage of multithreading whilst utilizing mutex locks and a queue for resource allocation.

# to use

you may clone the repository:

```
git clone https://github.com/Rmehadje/philosophers.git
make
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals(optional)]
