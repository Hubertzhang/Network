//
//  AGServer.h
//  Network
//
//  Created by Hubert on 13-11-20.
//  Copyright (c) 2013年 Hubert. All rights reserved.
//

#ifndef __Network__AGServer__
#define __Network__AGServer__

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <vector>
using namespace boost::asio;
using boost::system::error_code;
using ip::tcp;
using std::vector;
class AGServer
{
    io_service &m_iosev;
    tcp::endpoint clientAddr;
    ip::tcp::acceptor m_acceptor;
    vector<int> buf;
    void acceptHandler(boost::shared_ptr<tcp::socket> psocket, boost::system::error_code ec);
    void recieveHandler(boost::shared_ptr<tcp::socket> psocket, boost::system::error_code ec);
    void readHandler(boost::shared_ptr<tcp::socket> psocket, boost::system::error_code ec);
    void conncetHandler(boost::shared_ptr<tcp::socket> psocket, vector<int> message, boost::system::error_code ec);
    void writeHandler(error_code ec, size_t bytes_transferred);
public:
    AGServer(io_service &iosev);
    void setup(char*);
    void recieve();
    void send(vector<int> message);
};

#endif /* defined(__Network__AGServer__) */