function maxProfit(prices: number[]): number {
    var mn = 100000, mx = -1, mxDiff = 0;
    var mnPrice: Array<number> = [];
    var mxPrice: Array<number> = [];
    for (let i = 0; i < prices.length; i++) {
        mnPrice.push(Math.min(mn,prices[i]));
        mn = Math.min(mn,prices[i]);
    }
    for (let i = prices.length - 1; i >= 0; i--) {
        mxPrice.push(Math.max(mx,prices[i]));
        mx = Math.max(mx,prices[i]);
    }
    mxPrice.reverse();
    //console.log(mnPrice);
    //console.log(mxPrice);
    for (let i = 0; i < prices.length; i++) {
        mxDiff = Math.max(mxDiff,mxPrice[i]-mnPrice[i]);
    }
    return mxDiff;
};