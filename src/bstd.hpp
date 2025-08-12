#pragma once
#include <string>
#include <string_view>
#include <sstream>
#include <vector>

namespace bstd {
    namespace strings {
        inline bool has_prefix(const std::string& str, const std::string& prefix){
            std::string_view view(str);
            if (prefix.size() > view.size()) return false;

            return view.substr(0, prefix.size()) == prefix;
        }

        inline bool has_suffix(const std::string& str, const std::string& suffix) {
            std::string_view view(str);
            if (suffix.size() > view.size()) return false; // avoid UB
            return view.substr(view.size() - suffix.size(), suffix.size()) == suffix;
        }

        inline std::vector<std::string> split(const std::string& str, char delimiter){
            std::stringstream ss(str);

            std::string tok;
            std::vector<std::string> toks;

            while (std::getline(ss, tok, delimiter)){
                toks.push_back(tok);
            }

            return toks;
        }

        inline void replace_all(std::string& str, const std::string& target, const std::string& replacement, size_t max_count = std::string::npos){
            if (target.empty()) return; // avoid infinite loop
            std::size_t start_pos = 0;
            std::size_t count = 0;

            while ((start_pos = str.find(target, start_pos)) != std::string::npos) {
                str.replace(start_pos, target.length(), replacement);
                start_pos += replacement.length(); // move past replaced part
                if (++count >= max_count) break; // stop if reached limit
            }
        }
    }



    namespace vectors {

    }



    namespace files {

    }
}