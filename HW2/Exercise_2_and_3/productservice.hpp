/**
 * productservice.hpp defines Bond and IRSwap ProductServices
 */

#include <iostream>
#include <map>
#include "products.hpp"
#include "soa.hpp"

 /**
  * Bond Product Service to own reference data over a set of bond securities.
  * Key is the productId string, value is a Bond.
  */
class BondProductService : public Service<string, Bond>
{

public:
	// BondProductService ctor
	BondProductService();

	// Return the bond data for a particular bond product identifier
	Bond& GetData(string productId);

	// Add a bond to the service (convenience method)
	void Add(Bond& bond);

	// Q3.1 Get all Bonds with the specified ticker
	vector<Bond> GetBonds(string& _ticker);

private:
	map<string, Bond> bondMap; // cache of bond products

};

/**
 * Interest Rate Swap Product Service to own reference data over a set of IR Swap products
 * Key is the productId string, value is a IRSwap.
 */
class IRSwapProductService : public Service<string, IRSwap>
{
public:
	// IRSwapProductService ctor
	IRSwapProductService();

	// Return the IR Swap data for a particular bond product identifier
	IRSwap& GetData(string productId);

	// Add a bond to the service (convenience method)
	void Add(IRSwap& swap);

	// Q3.2 Get all Swaps with the specified fixed leg day count convention
	vector<IRSwap> GetSwaps(DayCountConvention _fixedLegDayCountConvention);

	// Q3.3 Get all Swaps with the specified fixed leg payment frequency
	vector<IRSwap> GetSwaps(PaymentFrequency _fixedLegPaymentFrequency);

	// Q3.4 Get all Swaps with the specified floating index
	vector<IRSwap> GetSwaps(FloatingIndex _floatingIndex);

	// Q3.5 Get all Swaps with a term in years greater than the specified value
	vector<IRSwap> GetSwapsGreaterThan(int _termYears);

	// Q3.6 Get all Swaps with a term in years less than the specified value
	vector<IRSwap> GetSwapsLessThan(int _termYears);

	// Q3.7 Get all Swaps with the specified swap type
	vector<IRSwap> GetSwaps(SwapType _swapType);

	// Q3.8 Get all Swaps with the specified swap leg type
	vector<IRSwap> GetSwaps(SwapLegType _swapLegType);

private:
	map<string, IRSwap> swapMap; // cache of IR Swap products

};

BondProductService::BondProductService()
{
	bondMap = map<string, Bond>();
}

Bond& BondProductService::GetData(string productId)
{
	return bondMap[productId];
}

void BondProductService::Add(Bond& bond)
{
	bondMap.insert(pair<string, Bond>(bond.GetProductId(), bond));
}

// Q3.1 Get all Bonds with the specified ticker
vector<Bond> BondProductService::GetBonds(string& _ticker)
{
	vector<Bond> return_vec;
	for (map<string, Bond>::iterator it = bondMap.begin(); it != bondMap.end(); it++)
	{
		if ((it->second).GetTicker() == _ticker) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

IRSwapProductService::IRSwapProductService()
{
	swapMap = map<string, IRSwap>();
}

IRSwap& IRSwapProductService::GetData(string productId)
{
	return swapMap[productId];
}

void IRSwapProductService::Add(IRSwap& swap)
{
	swapMap.insert(pair<string, IRSwap>(swap.GetProductId(), swap));
}

// Q3.2 Get all Swaps with the specified fixed leg day count convention
vector<IRSwap> IRSwapProductService::GetSwaps(DayCountConvention _fixedLegDayCountConvention)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetFixedLegDayCountConvention() == _fixedLegDayCountConvention) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.3 Get all Swaps with the specified fixed leg payment frequency
vector<IRSwap> IRSwapProductService::GetSwaps(PaymentFrequency _fixedLegPaymentFrequency)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetFixedLegPaymentFrequency() == _fixedLegPaymentFrequency) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.4 Get all Swaps with the specified floating index
vector<IRSwap> IRSwapProductService::GetSwaps(FloatingIndex _floatingIndex)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetFloatingIndex() == _floatingIndex) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.5 Get all Swaps with a term in years greater than the specified value
vector<IRSwap> IRSwapProductService::GetSwapsGreaterThan(int _termYears)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetTermYears() > _termYears) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.6 Get all Swaps with a term in years less than the specified value
vector<IRSwap> IRSwapProductService::GetSwapsLessThan(int _termYears)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetTermYears() < _termYears) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.7 Get all Swaps with the specified swap type
vector<IRSwap> IRSwapProductService::GetSwaps(SwapType _swapType)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetSwapType() == _swapType) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

// Q3.8 Get all Swaps with the specified swap leg type
vector<IRSwap> IRSwapProductService::GetSwaps(SwapLegType _swapLegType)
{
	vector<IRSwap> return_vec;
	for (map<string, IRSwap>::iterator it = swapMap.begin(); it != swapMap.end(); it++)
	{
		if ((it->second).GetSwapLegType() == _swapLegType) { return_vec.push_back(it->second); }
	}
	return return_vec;
};

/**
 * Future Product Service to own reference data over a set of future products.
 * Key is the productId string, value is a Future.
 */
class FutureProductService : public Service<string, Future>
{
public:
	// FutureProductService ctor
	FutureProductService();

	// Return the future data for a particular future product identifier
	Future& GetData(string productId);

	// Add a future to the service (convenience method)
	void Add(Future& future);

private:
	map<string, Future> futureMap; // cache of future products

};

FutureProductService::FutureProductService()
{
	futureMap = map<string, Future>();
}

Future& FutureProductService::GetData(string productId)
{
	return futureMap[productId];
}

void FutureProductService::Add(Future& future)
{
	futureMap.insert(pair<string, Future>(future.GetProductId(), future));
}