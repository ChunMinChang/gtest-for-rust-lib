# gtest-for-rust-lib

*Cargo* brings a brilliant testing framework, but it cannot cover all the usecases when integrating *Rust* and *C/C++*.
In my real usecase, I have an abstract interface in *C* for different implementations on different platforms. Most of the platform-dependent implementations are written in *C/C++*, but one is written in *Rust*. Therefore, I need to have a testing framework that can call different API implementations via my abstract interfaces. The *googletest* is a good option for me.

However, there is some limitation when testing *Rust* APIs in *gtest*. For example, it's impossible to use *death test* for a *Rust* API (see *test_death.cpp*). This repo is used to list all the problems I found when bring *Rust* into *googletest*'s world.

## Build and run tests
Run `$ sh run.sh` (it will clean all the tests and rebuild all of them)

## Build tests
Run `$ sh build.sh`

## Clean tests
Run `$ sh clean.sh`
