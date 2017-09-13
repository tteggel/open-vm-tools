/*
 *  Created on: May 21, 2012
 *      Author: mdonahue
 *
 *  Copyright (c) 2012 VMware, Inc.  All rights reserved.
 *  -- VMware Confidential
 */

#ifndef BASICCANCELMETHOD_H_
#define BASICCANCELMETHOD_H_

namespace Caf { namespace AmqpClient {

/**
 * @author mdonahue
 * @ingroup AmqpApiImpl
 * @remark LIBRARY IMPLEMENTATION - NOT PART OF THE PUBLIC API
 * @brief Implementation of AMQP basic.cancel
 */
class BasicCancelMethod : public IServerMethod {
public:
	BasicCancelMethod();
	virtual ~BasicCancelMethod();

	/**
	 * @brief Initialize the method
	 * @param consumerTag the <i>consumer tag</i> associated with the consumer
	 */
	void init(
		const std::string& consumerTag);

public: // IServerMethod
	std::string getMethodName() const;

	AMQPStatus send(const SmartPtrCAmqpChannel& channel);

private:
	bool _isInitialized;
	std::string _consumerTag;

	CAF_CM_CREATE;
	CAF_CM_DECLARE_NOCOPY(BasicCancelMethod);
};
CAF_DECLARE_SMART_POINTER(BasicCancelMethod);

}}

#endif /* BASICCANCELMETHOD_H_ */