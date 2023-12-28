#pragma once

#include <string>

#include "define.h"
class MODELS_API User
{
public:
    User();
    User(const int id, const std::string& name, const std::string& email, const std::string& password, bool role);

    void SetId(int id);
    void SetName(const std::string& name);
    void SetEmail(const std::string& email);
    void SetPassword(const std::string& password);
    void SetImagePath(const std::string& imagePath);
    void SetRole(bool role);

    int GetId() const;
    std::string GetName() const;
    std::string GetEmail() const;
    std::string GetPassword() const;
    std::string GetImagePath() const;
    bool GetRole() const;

private:
    int m_id;
    std::string m_name;
    std::string m_email;
    std::string m_password;
    std::string m_imagePath;
    bool m_role;
};