#include "BoNetworkMessage.h"

void CBoNetworkMessage::Construct() {

}

void CBoNetworkPingMessage::Construct() {
	((CBoNetworkMessage *)this)->Construct();
}
