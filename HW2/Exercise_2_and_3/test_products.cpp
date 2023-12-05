/**
 * test program for our ProductServices
 */

#include <iostream>
#include "products.hpp"
#include "productservice.hpp"

using namespace std;

int main()
{
  // Create the 10Y treasury note
  date maturityDate(2025, Nov, 16);
  string cusip = "912828M56";
  Bond treasuryBond(cusip, CUSIP, "T", 2.25, maturityDate);

  // Create the 2Y treasury note
  date maturityDate2(2017, Nov, 5);
  string cusip2 = "912828TW0";
  Bond treasuryBond2(cusip2, CUSIP, "T", 0.75, maturityDate2);

  // Create a BondProductService
  BondProductService *bondProductService = new BondProductService();

  // Add the 10Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond);
  Bond bond = bondProductService->GetData(cusip);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Add the 2Y note to the BondProductService and retrieve it from the service
  bondProductService->Add(treasuryBond2);
  bond = bondProductService->GetData(cusip2);
  cout << "CUSIP: " << bond.GetProductId() << " ==> " << bond << endl;

  // Create the Spot 10Y Outright Swap
  date effectiveDate(2015, Nov, 16);
  date terminationDate(2025, Nov, 16);
  string outright10Y = "Spot-Outright-10Y";
  IRSwap outright10YSwap(outright10Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate, terminationDate, USD, 10, SPOT, OUTRIGHT);

  // Create the IMM 2Y Outright Swap
  date effectiveDate2(2015, Dec, 20);
  date terminationDate2(2017, Dec, 20);
  string imm2Y = "IMM-Outright-2Y";
  IRSwap imm2YSwap(imm2Y, THIRTY_THREE_SIXTY, THIRTY_THREE_SIXTY, SEMI_ANNUAL, LIBOR, TENOR_3M, effectiveDate2, terminationDate2, USD, 2, IMM, OUTRIGHT);

  // Create a IRSwapProductService
  IRSwapProductService *swapProductService = new IRSwapProductService();

  // Add the Spot 10Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(outright10YSwap);
  IRSwap swap = swapProductService->GetData(outright10Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;

  // Add the IMM 2Y Outright Swap to the IRSwapProductService and retrieve it from the service
  swapProductService->Add(imm2YSwap);
  swap = swapProductService->GetData(imm2Y);
  cout << "Swap: " << swap.GetProductId() << " == > " << swap << endl;


  //Q3 Test the searching methods implemented in productservice.hpp
  cout << "Q3 Test the searching methods" << endl;
  // Q3.1 Get all Bonds with the specified ticker
  cout << "Q3.1 Get all Bonds with the specified ticker" << endl;
  vector<Bond> vec1; string ticker = "T";
  vec1 = bondProductService->GetBonds(ticker);
  for (auto i = vec1.begin(); i != vec1.end(); i++) { cout << *i << endl; }
  // Q3.2 Get all Swaps with the specified fixed leg day count convention
  cout << "Q3.2 Get all Swaps with the specified fixed leg day count convention" << endl;
  vector<IRSwap> vec2;
  vec2 = swapProductService->GetSwaps(THIRTY_THREE_SIXTY);
  for (auto i = vec2.begin(); i != vec2.end(); i++) { cout << *i << endl; }
  // Q3.3 Get all Swaps with the specified fixed leg payment frequency
  cout << "Q3.3 Get all Swaps with the specified fixed leg payment frequency" << endl;
  vector<IRSwap> vec3;
  vec3 = swapProductService->GetSwaps(SEMI_ANNUAL);
  for (auto i = vec3.begin(); i != vec3.end(); i++) { cout << *i << endl; }
  // Q3.4 Get all Swaps with the specified floating index
  cout << "Q3.4 Get all Swaps with the specified floating index" << endl;
  vector<IRSwap> vec4;
  vec4 = swapProductService->GetSwaps(LIBOR);
  for (auto i = vec4.begin(); i != vec4.end(); i++) { cout << *i << endl; }
  // Q3.5 Get all Swaps with a term in years greater than the specified value
  cout << "Q3.5 Get all Swaps with a term in years greater than the specified value" << endl;
  vector<IRSwap> vec5;
  vec5 = swapProductService->GetSwapsGreaterThan(5);
  for (auto i = vec5.begin(); i != vec5.end(); i++) { cout << *i << endl; }
  // Q3.6 Get all Swaps with a term in years less than the specified value
  cout << "Q3.6 Get all Swaps with a term in years less than the specified value" << endl;
  vector<IRSwap> vec6;
  vec6 = swapProductService->GetSwapsLessThan(5);
  for (auto i = vec6.begin(); i != vec6.end(); i++) { cout << *i << endl; }
  // Q3.7 Get all Swaps with the specified swap type
  cout << "Q3.7 Get all Swaps with the specified swap type" << endl;
  vector<IRSwap> vec7;
  vec7 = swapProductService->GetSwaps(IMM);
  for (auto i = vec7.begin(); i != vec7.end(); i++) { cout << *i << endl; }
  // Q3.8 Get all Swaps with the specified swap leg type
  cout << "Q3.8 Get all Swaps with the specified swap leg type" << endl;
  vector<IRSwap> vec8;
  vec8 = swapProductService->GetSwaps(OUTRIGHT);
  for (auto i = vec8.begin(); i != vec8.end(); i++) { cout << *i << endl; }

  return 0;
}
