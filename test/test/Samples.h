// © Copyright 2014 TokBox. All Rights Reserved.
#ifndef TEST_TEST_SAMPLES_H_
#define TEST_TEST_SAMPLES_H_

const uint8_t kBasicRtpPacket[] = {
  0x80, 0x74, 0xd3, 0xb0, 0x84, 0xec, 0x5b, 0x0a, 0xbb, 0x42, 0xe9, 0x45,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const std::string kCertificatePath = "/tmp/__mantis_certificate.pem";

const std::string kCertificateFingerprint =
"sha-256 20:A5:BD:A7:22:F3:26:B5:66:23:DC:1F:84:58:29:65:1B:2A:11:64:A5:1E:8F:31:B9:7C:A0:5E:7D:FC:C6:00";

const std::string kCertificate =
"-----BEGIN RSA PRIVATE KEY-----\r\n"
"MIICXAIBAAKBgQC+8nmAzlBJOScU3/wvw235n7tldzbM9qtNSpH5z0NFauLyP22d\r\n"
"5YcE4fO7A3vfZWCEBW9/FQIaTbZ48lCZ9LyZP9NYd68KnnY4nKfX9VCVLiupfo+F\r\n"
"JKT6iyx+2tuPLiUzHEhHSokPusOF7aQGS2i67lFVZOR6eqruSP7kFgBKUQIDAQAB\r\n"
"AoGAGiq2Vd1wCSjI30Z2k8EPUBcAoj39B4eCIBxo9rfdeyTTpujkR7ANmbCxKt6m\r\n"
"Wg3VdSIdjme9mwctS1PBkeeE9KqmAKT+MA+tCx2oAVOjmoKbL+POdvmhiRtrbIWg\r\n"
"vv2vbOS9B/yBYeHXH7TVm5uZ56ZNPjIbuUzh8wB/LUtx97ECQQDp6AR+mbRm7quu\r\n"
"+4v61ZdkV62CwtCRSlkMBgW9TicLDWSvmKA49RmreOfZ+mcfwSCroQPC5NlspMly\r\n"
"5woZ+4k1AkEA0PuuaxP+2qiQledjKa+imJv1ZjKAaM+B25qo2/SiBIYwMNQeLJcA\r\n"
"B645veIa9ct7lWmHGPNcSMsdNn2ecvX8LQJAfJio/D8oB8SPE3DPSdhJApxpwsO/\r\n"
"kgVGlc8Hc6WTyqFhxt/ISU7WU67d4hEuqY2Yt5PXixOYdfT5kglcKicBGQJAT0a6\r\n"
"UppiOlZpisQdBOpAlv3KqLsNpTTagRD5b38smuTAkTVWQPoDI+a+tr54FbfcKMDA\r\n"
"ZAGlh2OtsEcU/W08/QJBAMka5EdqF9f3CMyeC0/gfCM+vg1i7bsEbVf6fPsl7anp\r\n"
"KBy6yZNyrzM5XP3C/3mLotBIUpvisx6KIxXHy4jF164=\r\n"
"-----END RSA PRIVATE KEY-----\r\n"
"-----BEGIN CERTIFICATE-----\r\n"
"MIICATCCAWoCCQDYNUHEsN+u3TANBgkqhkiG9w0BAQUFADBFMQswCQYDVQQGEwJV\r\n"
"UzETMBEGA1UECBMKU29tZS1TdGF0ZTEhMB8GA1UEChMYSW50ZXJuZXQgV2lkZ2l0\r\n"
"cyBQdHkgTHRkMB4XDTE0MDkxMTAwMTAxNloXDTE1MDkxMTAwMTAxNlowRTELMAkG\r\n"
"A1UEBhMCVVMxEzARBgNVBAgTClNvbWUtU3RhdGUxITAfBgNVBAoTGEludGVybmV0\r\n"
"IFdpZGdpdHMgUHR5IEx0ZDCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAvvJ5\r\n"
"gM5QSTknFN/8L8Nt+Z+7ZXc2zParTUqR+c9DRWri8j9tneWHBOHzuwN732VghAVv\r\n"
"fxUCGk22ePJQmfS8mT/TWHevCp52OJyn1/VQlS4rqX6PhSSk+ossftrbjy4lMxxI\r\n"
"R0qJD7rDhe2kBktouu5RVWTkenqq7kj+5BYASlECAwEAATANBgkqhkiG9w0BAQUF\r\n"
"AAOBgQAt6pAYxN5GEgXagngwfIg2P9vZahpqgQ4VTjhc13GyCxHaSXKdziy+CU2K\r\n"
"031RW7wqdlCLVa86X1yt19J/UNfwax52KPS8xous5prdnNrpV83fu3rFcmutK0XD\r\n"
"JLLMmVGdgY9UPDwtxN3r0QpPAN/0I0y2w0qNbf34CxVPa847ZA==\r\n"
"-----END CERTIFICATE-----\r\n";

const std::string kFirefoxSdpOffer =
"v=0\r\n"
"o=Mozilla-SIPUA-32.0.1 23534 0 IN IP4 0.0.0.0\r\n"
"s=SIP Call\r\n"
"t=0 0\r\n"
"a=ice-ufrag:afb952b0\r\n"
"a=ice-pwd:a68767d02a4c2f11846ec96a1abd9f16\r\n"
"a=fingerprint:sha-256 91:91:08:F5:8D:D0:4E:0C:18:4E:FB:EC:10:B9:F3:1F:BE:C8:D3:47:54:56:79:ED:DD:03:CB:36:17:5F:01:B3\r\n"  // NOLINT
"m=audio 60625 RTP/SAVPF 109 0 8 101\r\n"
"c=IN IP4 216.38.134.120\r\n"
"a=rtpmap:109 opus/48000/2\r\n"
"a=ptime:20\r\n"
"a=rtpmap:0 PCMU/8000\r\n"
"a=rtpmap:8 PCMA/8000\r\n"
"a=rtpmap:101 telephone-event/8000\r\n"
"a=fmtp:101 0-15\r\n"
"a=sendrecv\r\n"
"a=extmap:1 urn:ietf:params:rtp-hdrext:ssrc-audio-level\r\n"
"a=setup:actpass\r\n"
"a=candidate:0 1 UDP 2130379007 192.168.10.112 60625 typ host\r\n"
"a=candidate:1 1 UDP 1694236671 216.38.134.120 60625 typ srflx raddr 192.168.10.112 rport 60625\r\n"
"a=candidate:0 2 UDP 2130379006 192.168.10.112 51900 typ host\r\n"
"a=rtcp-mux\r\n"
"m=video 60940 RTP/SAVPF 120\r\n"
"c=IN IP4 192.168.10.112\r\n"
"a=rtpmap:120 VP8/90000\r\n"
"a=sendrecv\r\n"
"a=rtcp-fb:120 nack\r\n"
"a=rtcp-fb:120 nack pli\r\n"
"a=rtcp-fb:120 ccm fir\r\n"
"a=setup:actpass\r\n"
"a=candidate:0 1 UDP 2130379007 192.168.10.112 60940 typ host\r\n"
"a=candidate:0 2 UDP 2130379006 192.168.10.112 63736 typ host\r\n"
"a=rtcp-mux\r\n";

const std::string kSdpOffer =
"v=0\r\n"
"o=- 3648180302 1886658065 IN IP4 127.0.0.1\r\n"
"s=-\r\n"
"c=IN IP4 127.0.0.1\r\n"
"t=0 0\r\n"
"a=fingerprint:sha-256 91:91:08:F5:8D:D0:4E:0C:18:4E:FB:EC:10:B9:F3:1F:BE:C8:D3:47:54:56:79:ED:DD:03:CB:36:17:5F:01:B3\r\n"  // NOLINT
"m=audio 60625 RTP/SAVPF 109 0 8 101\r\n"
"c=IN IP4 216.38.134.120\r\n"
"a=rtpmap:109 opus/48000/2\r\n"
"a=rtpmap:0 PCMU/8000\r\n"
"a=rtpmap:8 PCMA/8000\r\n"
"a=rtpmap:101 telephone-event/8000\r\n"
"a=rtcp:51900\r\n"
"a=sendrecv\r\n"
"a=ice-ufrag:afb952b0\r\n"
"a=ice-pwd:a68767d02a4c2f11846ec96a1abd9f16\r\n"
"a=candidate:0 1 UDP 2130379007 192.168.10.112 60625 typ host\r\n"
"a=candidate:1 1 UDP 1694236671 216.38.134.120 60625 typ srflx raddr 192.168.10.112 rport 60625\r\n"
"a=candidate:0 2 UDP 2130379006 192.168.10.112 51900 typ host\r\n"
"m=video 60940 RTP/SAVPF 120\r\n"
"c=IN IP4 192.168.10.112\r\n"
"a=rtpmap:120 VP8/90000\r\n"
"a=rtcp:63736\r\n"
"a=sendrecv\r\n"
"a=ice-ufrag:afb952b0\r\n"
"a=ice-pwd:a68767d02a4c2f11846ec96a1abd9f16\r\n"
"a=candidate:0 1 UDP 2130379007 192.168.10.112 60940 typ host\r\n"
"a=candidate:0 2 UDP 2130379006 192.168.10.112 63736 typ host\r\n";

#endif  // TEST_TEST_SAMPLES_H_
