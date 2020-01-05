/**
 * @file OptionalSerialization.hpp
 * @author paul
 * @date 25.04.19
 * @brief Adds serialization and deserialization for std::optional<T> if T is serializable
 */

#ifndef SERVER_OPTIONALSERIALIZATION_HPP
#define SERVER_OPTIONALSERIALIZATION_HPP

#include <nlohmann/json.hpp>

namespace std {
    template<typename T>
    void to_json(nlohmann::json &j, const std::optional<T> &t) {
        if (t.has_value()) {
            j = t.value();
        } else {
            j = nullptr;
        }
    }

    template<typename T>
    void from_json(const nlohmann::json &j, std::optional<T> &t) {
        if (j.is_null()) {
            t = std::nullopt;
        } else {
            t = j.get<T>();
        }
    }
}

#endif //SERVER_OPTIONALSERIALIZATION_HPP