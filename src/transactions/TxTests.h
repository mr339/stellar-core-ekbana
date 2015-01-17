#include "crypto/SecretKey.h"

namespace stellar
{
    class TransactionFrame;
    typedef shared_ptr<TransactionFrame> TransactionFramePtr;
namespace txtest
{

SecretKey getRoot();

SecretKey getAccount(const char* n);

TransactionFramePtr setTrust(SecretKey& from, SecretKey& to, uint32_t seq, const std::string& currencyCode);
void applyTrust(Application& app, SecretKey& from, SecretKey& to, uint32_t seq, const std::string& currencyCode);

TransactionFramePtr createPaymentTx(SecretKey& from, SecretKey& to, uint32_t seq, uint64_t amount);
void applyPaymentTx(Application& app, SecretKey& from, SecretKey& to, uint32_t seq, uint64_t amount);

TransactionFramePtr createCreditPaymentTx(SecretKey& from, SecretKey& to, Currency& ci, uint32_t seq,
    uint64_t amount);
void applyCreditPaymentTx(Application& app, SecretKey& from, SecretKey& to, Currency& ci, uint32_t seq,
    uint64_t amount);

TransactionFramePtr createOfferTx(SecretKey& source, Currency& takerGets, 
    Currency& takerPays, uint64_t price,uint64_t amount, uint32_t seq);

void applyOffer(Application& app, SecretKey& source, Currency& takerGets,
    Currency& takerPays, uint64_t price, uint64_t amount, uint32_t seq);

Currency makeCurrency(SecretKey& issuer, const std::string& code);

}  // end txtest namespace
}