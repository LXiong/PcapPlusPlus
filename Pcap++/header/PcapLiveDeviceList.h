#ifndef PCAPPP_LIVE_DEVICE_LIST
#define PCAPPP_LIVE_DEVICE_LIST

#include <IpAddress.h>
#include <PcapLiveDevice.h>
#include <WinPcapLiveDevice.h>
#include <vector>

using namespace std;

/// @file

/**
 * @class PcapLiveDeviceList
 * A singleton class that creates, stores and provides access to all PcapLiveDevice (on Linux) or WinPcapLiveDevice (on Windows) instances. All live
 * devices are initialized on startup and wrap the network interfaces installed on the machine. This class enables access to them through
 * their IP addresses or get a vector of all of them so the user can search them in some other way
 */
class PcapLiveDeviceList
{
private:
	vector<PcapLiveDevice*> m_LiveDeviceList;

	// private c'tor
	PcapLiveDeviceList();
	// private copy c'tor
	PcapLiveDeviceList( const PcapLiveDeviceList& other );
	PcapLiveDeviceList& operator=(const PcapLiveDeviceList& other);
	// private d'tor
	~PcapLiveDeviceList();
public:
	/**
	 * The access method to the singleton
	 * @return The singleton instance of this class
	 */
	static inline PcapLiveDeviceList& getInstance()
	{
		static PcapLiveDeviceList instance;
		return instance;
	}

	/**
	 * @return A vector containing pointers to all live devices currently installed on the machine
	 */
	inline const vector<PcapLiveDevice*>& getPcapLiveDevicesList() { return m_LiveDeviceList; }

	/**
	 * Get a pointer to the live device by its IP address. IP address can be both IPv4 or IPv6
	 * @param[in] ipAddr The IP address defined for the device
	 * @return A pointer to the live device if this IP address exists. NULL otherwise
	 */
	PcapLiveDevice* getPcapLiveDeviceByIp(IPAddress* ipAddr);

	/**
	 * Get a pointer to the live device by its IPv4 address
	 * @param[in] ipAddr The IPv4 address defined for the device
	 * @return A pointer to the live device if this IPv4 address exists. NULL otherwise
	 */
	PcapLiveDevice* getPcapLiveDeviceByIp(IPv4Address ipAddr);

	/**
	 * Get a pointer to the live device by its IPv6 address
	 * @param[in] ip6Addr The IPv6 address defined for the device
	 * @return A pointer to the live device if this IPv6 address exists. NULL otherwise
	 */
	PcapLiveDevice* getPcapLiveDeviceByIp(IPv6Address ip6Addr);

	/**
	 * Get a pointer to the live device by its IP address represented as string. IP address can be both IPv4 or IPv6
	 * @param[in] ipAddrAsString The IP address defined for the device as string
	 * @return A pointer to the live device if this IP address is valid and exists. NULL otherwise
	 */
	PcapLiveDevice* getPcapLiveDeviceByIp(const char* ipAddrAsString);
};

#endif
