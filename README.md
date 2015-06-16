# Cpp-MultiClientServer
Multi-threaded server and client build using C++, Winsock and POSIX threads library.

# FYPStockLearner
A web based application that uses machine learning to identify buying and selling signals in the stock market.

The application allows the user to train a classfier using supervised machine learning to recognize optimal buying and selling points based on technical indicators, which are statistical signals used by professional traders used to identify when they should buy or sell a stock. Some signals are more accurate than others and a combination of signals may produce the highest level of accuracy. The user will be able to select which signals to use allowing them to fine tune the learning process using trial and error to find the most informative combination of signals.

One of the major design requirements of the prototype is modularity - it must allow additional machine learning and technical indicator support to be easily added in future. To do this the application will be built in two stages. First the main skeleton which provides core functionality such as application state, security and user interaction will be built. Secondly, ‘modules’ will be added with each module providing support for a single learning method or technical indicator signal. For example, if we want the prototype to learn using a Decision Tree approach then we will build and attach a Decision Tree learning module to provide this option. Similarly, if we want the application to use RSI trading signals to train the machine we will build a module for calculating RSI values in stock data and detecting when the RSI values produce a buying or selling signal. 

## Technologies Used

### Development
* C++
* Winsock - Windows sockets API
* POSIX - provides an API for creating and manipulating threads
* MySQL
