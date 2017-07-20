// PAC demo
function FindProxyForURL(url, host) {
    if (url.substring(0, 5) == "http:") {
        return "PROXY http-proxy.mydomain.com:8080"
    } else if (url.substring(0, 4) == "ftp:") {
        return "PROXY ftp-proxy.mydomain.com:8080"
    } else {
        return "DIRECT"
    }
}