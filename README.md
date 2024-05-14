### `my_robot_manager`

#### `/log_current_position` service

1. It's a `std_srvs::Trigger` service.
2. Call:
   1. `rosservice call /ToyBot/log_current_position "{}"`.
   2. `rosservice call /BoyTot/log_current_position "{}"`.

#### Constructor order of member initializations

The constructor initializes class members in the order of their declaration, no in the order of the initialization list. Make sure that dependencies are declared in the right order.

For example, got the following response to `rosrun my_robot_manager robot_manager_node`:

```
[ WARN] [1715728696.274100076]: couldn't register subscriber on topic [/]
[ INFO] [1715728696.275512765]: Robot 1 created.
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
Aborted (core dumped)
```

Because member `odometry_topic` was declared after member `_pos_srv`, which required an existing topic for initialization. The default for `odometry_topic` was `/odom`, while the correct values after initialization were `/robot1/odom` and `/robot2/odom`, with `/odom` non-existent.
