//
// factory.hpp
//
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#ifndef VSOMEIP_FACTORY_HPP
#define VSOMEIP_FACTORY_HPP

#include <vsomeip/enumeration_types.hpp>

namespace vsomeip {

class message;

class serializer;
class deserializer;

class endpoint;
class client;
class service;

class factory {
public:
	static factory * get_default_factory();
	virtual ~factory() {};

	virtual message * create_message() const = 0;
	virtual serializer * create_serializer() const = 0;
	virtual deserializer * create_deserializer(uint8_t *_data = 0, uint32_t _length = 0) const = 0;

	virtual endpoint * create_endpoint() const = 0;
	virtual client * create_client(const endpoint &_endpoint) const = 0;
	virtual service * create_service(const endpoint &_endpoint) const = 0;
};

}; // namespace vsomeip

#endif // VSOMEIP_FACTORY_HPP
